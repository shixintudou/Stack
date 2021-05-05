#include"plv.h"
#include<dos.h>
int putbmp(int x, int y, char* s)
{
    FILE* fp;
    long begin, w, h;
    unsigned char k;
    unsigned char color[256],R, G, B;
    unsigned int i, j, bit;
    if ((fp = fopen(s, "rb")) == NULL)
    {
        printf("not open");
        return 1;
    }
    fseek(fp, 10L, 0);
    fread(&begin, 4, 1, fp);
    fseek(fp, 18L, 0);
    fread(&w, 4, 1, fp);
    fread(&h, 4, 1, fp);
    fseek(fp, 28L, 0);
    fread(&bit, 2, 1, fp);
    if (bit != 8)
    {
        fclose(fp);
        printf("bit:%d,not 8", bit);
        return 2;
    }
    fseek(fp, 54L, 0);
    for (i = 0; i < 256; i++)
    {
        fread(&B, 1, 1, fp);
        fread(&G, 1, 1, fp);
        fread(&R, 1, 1, fp);
        if (R < 42)
        {

            color[i] = (B > 84) + 2 * (G > 84);
        }
        else if (R < 126)
        {
            color[i] = 8 + (B > 168) + 2 * (G > 168);
        }
        else if (R < 210)
        {
            color[i] = 4 + (B > 84) + 2 * (G > 60);
        }
        else
        {
            color[i] = 12 + (B > 168) + 2 * (G > 168);
        }

        fseek(fp, 1, 1);
    }
    for (i = 0; i < h; i++)
    {
        fseek(fp, begin + (w + 3) / 4 * i * 4, 0);
        for (j = 0; j < w; j++)
        {

            fread(&k, 1, 1, fp);
            putpixel(x + j, y + h - i - 1, color[k]);
        }
    }
    fclose(fp);
    return 0;
}
void load_pic(char* name)
{
    FILE* fp;
    int k = 8;
    register int i;
    register long j, t;
    int h, w;
    //long s;
    char far* ptr;    
    if (fp = fopen(name, "rb") == NULL)
    {
        closegraph();
        printf("flie open error\n");
        exit(1);
    }
    fread(&w, 4, 1, fp);
    fread(&h, 4, 1, fp);
    //s = 80 * w / 640 * h;
    /*closegraph();
    printf("%ld",s);
    exit(1);*/
    for (i = 0; i < h; i++)
    {            
        k = 8;
        for (j = 0; j < 4; j++)
        {
            outportb(0x3c4, 2);
            outportb(0x3c5, k); 
            ptr = (char far*)0xa0000000L + i * 80;
            for (t = 0; t < w/8; t++)
            {                
                *ptr = getc(fp);
                ptr++;
            }
            k /= 2;
        }                       
    }
    fclose(fp);
    outportb(0x3c5, 0xf);
}
int bmp_convert(char* bmp, char* dbm)	//将 *.bmp 变为 *.dbm,字符串bmp中为bmp所在地址，字dbmp为输出地址
{
    static int color[16] = { 0,4,2,6,1,5,3,7,8,12,10,14,9,13,11,15 }; //上win下ps
    unsigned char dbmline[640], bmpline[640], pixel[8], Vbyte;
    int ImageW, ImageH, i, j, k, n, now, bmpcom, gg;
    long hangsize;
    FILE* fbmp, * fdbm;
    union {
        unsigned char val;
        struct {
            unsigned cl : 4;
            unsigned ch : 4;
        }color;	//用位域储存颜色信息，分拆颜色信息 
    }MyColor;
    if ((fbmp = fopen(bmp, "rb")) == NULL)
    {
        printf("%s\n", bmp);
        printf("Open bmp error!");
        return 1;
    }
    fseek(fbmp, 18, SEEK_SET);	//bmp图像的宽高在文件头18字节后
    fread(&gg, 4, 1, fbmp);
    //	fread(&ImageW,4,1,fbmp);
    fread(&ImageH, 4, 1, fbmp);
    ImageW = gg;
    //	ImageH*=2;
     //	printf("%d ",ImageW);
     //	printf("%d",ImageH);
    if (ImageW == 0 || ImageH == 0 || ImageW > 640 || ImageH > 480)
    {
        printf("The image is too large!Please input image below 640*480.");
        fclose(fbmp);
        return 1;
    }
    if ((fdbm = fopen(dbm, "wb")) == NULL)
    {
        printf("Creat \"%s\" error!", dbm);
        return 1;
    }
    bmpcom = (ImageW - 1) / 8 + 1;	//行处理单元数
    hangsize = bmpcom * 4;	//每行字节数（DIB数据要求每行字节为4整数倍，已计算补零）
    fwrite(&ImageW, sizeof(int), 1, fdbm);
    fwrite(&ImageH, sizeof(int), 1, fdbm);
    fseek(fbmp, -hangsize, SEEK_END);
    for (i = 0; i < ImageH; i++)
    {
        now = 0;
        fread(bmpline, hangsize, 1, fbmp);
        fseek(fbmp, -hangsize * 2, SEEK_CUR);
        for (n = 3; n >= 0; n--)	//每行拆成四个位面的数据输出
      // for(n=0;n<=3;n++)
        {
            for (j = 0; j < bmpcom; j++)
            {
                Vbyte = 0;
                for (k = 0; k < 4; k++)
                {
                    MyColor.val = bmpline[j * 4 + k];
                    pixel[k * 2] = color[MyColor.color.ch];
                    pixel[k * 2 + 1] = color[MyColor.color.cl];
                }
                for (k = 0; k < 8; k++)
                {
                    Vbyte += (pixel[k] >> n & 1) << (7 - k);
                }
                dbmline[now++] = Vbyte;
            }
        }
        fwrite(dbmline, hangsize, 1, fdbm);
    }
    fclose(fdbm);
    fclose(fbmp);
    return 0;
}
int show_dbm(int x, int y, char* dbm)	//输入dbmp的路径,在(x,y)输出图片(x需为8的倍数)
{
    int ImageW, ImageH, n, i, j;
    long hangsize;
    FILE* fdbm;
    char far* per;
    per = (char far*)0xa0000000l;

    //	_VideoBusy=YES;			//hanenv系统内的显示寄存器保护变量 

    if ((fdbm = fopen(dbm, "rb")) == NULL)
    {
        //	printf("%s",dbm);
        //	getchar();
        //	printf("Open Error!");
        return 1;
    }
    fread(&ImageW, sizeof(int), 1, fdbm);
    fread(&ImageH, sizeof(int), 1, fdbm);
    //	printf("%d %d",ImageW,ImageH);
    hangsize = (ImageW - 1) / 8;
    per = per + x / 8 + y * 80;
    //if ((ImageH + y) > 480)	ImageH = 480 - y; 	//VGAMED  640*350
    for (i = 0; i < ImageH; i++)
    {
        for (n = 8; n >=1; n >>= 1)	//从第三位颜色平面写到第0
        {
            outportb(0x3c4, 2);
            outportb(0x3c5, n);
            fread(per, hangsize, 1, fdbm);
            fseek(fdbm, 1, SEEK_CUR);
        }
        //	fseek(fdbm,hangsize*2,SEEK_CUR);
        per += 80;
    }
    fclose(fdbm);

    //	_VideoBusy=NO;	

    outportb(0x3c5, 0xf);
    return 0;
}
