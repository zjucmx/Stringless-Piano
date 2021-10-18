#include "sys_fun.h"
#include "image.h"
#include "songs.h"
#include "display.h"
#include <stdio.h>
#include <stdlib.h>
#define uchar unsigned char
	
char dot_h=0x2e;
char dot_l=0x07;
uchar start=1;
uchar key,k=0;
uchar Count;
uchar game2_number;
uchar temp[3];
uchar grade;
uchar m,n; 
uchar key_1,key_tune;
uchar time=0;
uchar play_judge = 0;
uchar *game2_num[]={"16472","56223","42356","23552","75367"};
uchar code game2_check[5][5]={{1,6,4,7,2},{5,6,2,2,3},{4,2,3,5,6},{2,3,5,5,2},{7,5,3,6,7}};
	
void play_start(uchar (*music)[2]);
void show_score(uchar (*music)[2]);
void delay(uchar p);

void main()
{ 
	uchar i=0,j=0;
	uchar i_cide=0,key_cide;
	uchar clong,hight;
	hight=32;
	clong=16;
	Ini_Lcd();//Һ����ʼ���ӳ���
	WRGDRAM(0x80,clong,hight,gImage_1);//����֮��
	play_start(music0);		
	P4M1=0x00;
	P4M0=0x00;
	Ini_Lcd();//Һ����ʼ���ӳ���
	WRCGRAM1(0x40);
	WRCGRAM2(0x50);
	WRCGRAM3(0x60);
	WRCGRAM4(0x70);
	Disp(1,0,16,"�㽭��ѧ���ѧԺ");//��ʾ���ݵ�LCD12864�ӳ���			
	Disp(2,1,14,"����ϵͳ���");//��ʾ���ݵ�LCD12864�ӳ���
	Disp(3,1,12,"from��������");//��ʾ���ݵ�LCD12864�ӳ���
	Disp(4,1,12,"n:3180101484");//��ʾ���ݵ�LCD12864�ӳ���
	delay(20);
	start=0;	
	Ini_Lcd();
    Disp(1,3,4,"����");
    for (i=0;i<5;i++)
    {
    Write_Cmd(0x9A+i);
    Write_Data(0x00);
    Write_Data(0x00);
    }
    Write_Cmd(0x9A+i_cide);
    Write_Data(0x00);
    Write_Data(0x02);
    while (1)
    {
        bit flag_cide;
        flag_cide=0;
        key_cide=00;
        while (1)
        {
            KeyIO=0xf0;
            if((KeyIO&0xf0)!=0xf0)
            {
                Delay_xMs(100);
                if ((KeyIO&0xf0)!=0xf0)
                {
                key_cide=scankey();
                KeyIO=0xf0;
                while (KeyIO!=0xf0);
                break;
                }
            }
        }
        switch (key_cide)
        {
            case 11:
            cide[i_cide]=1+0x30;
            break;
            case 12:
            cide[i_cide]=2+0x30;
            break;
            case 13:
            cide[i_cide]=3+0x30;
            break;
            case 14:
            cide[i_cide]=4+0x30;
            break;
            case 21:
            cide[i_cide]=5+0x30;
            break;
            case 22:
            cide[i_cide]=6+0x30;
            break;
            case 23:
            cide[i_cide]=7+0x30;
            break;
            case 24:
            cide[i_cide]=8+0x30;
            break;
            case 31:
            cide[i_cide]=9+0x30;
            break;
            default:
            if (i_cide)
            {
            if (i_cide<4||cide[4]==0x30)
            {
            i_cide--;
            cide[i_cide]=0+0x30;
            }
            else
            cide[i_cide]=0+0x30;
            }
            break;
        }
        if (i_cide<4&&key_cide<32)
        i_cide++;  
        for (i=0;i<5;i++)
        {
            if (cide[i]-0x30)
            Disp(3,i+2,1,cide+i);
            else
            Disp(3,i+2,2," ");
        }
        for (i=0;i<5;i++)
        {
        Write_Cmd(0x9A+i);
        Write_Data(0x00);
        Write_Data(0x00);
        }
        Write_Cmd(0x9A+i_cide);
        Write_Data(0x00);
        Write_Data(0x02);
        if (i_cide==4&&key_cide<32)
        {
            flag_cide=1;
            for (i=0;i<5;i++)
            if (cide[i]!=cide_check[i])
            {
            flag_cide=0;
            break;
            }
        }
        if (flag_cide)
        break;
    }

	
	while(1)
	{
		key_1=00;
		KeyIO=0xf0;
		P4M1=0x00;
		P4M0=0x00;
		Ini_Lcd();//Һ����ʼ���ӳ���			
		Disp(1,0,8,"�˵�����");//��ʾ���ݵ�LCD12864�ӳ���
		Disp(2,0,10,"1.����ѡ��");//��ʾ���ݵ�LCD12864�ӳ���
		Disp(3,0,10,"2.��������");//��ʾ���ݵ�LCD12864�ӳ���
		Disp(4,0,10,"3.��Ϸģ��");//��ʾ���ݵ�LCD12864�ӳ���
		while (1)
			{
				if ((KeyIO&0xf0)!=0xf0)
				Delay_xMs(100);
				if((KeyIO&0xf0)!=0xf0){
				key_1=scankey();
                if (key_1>=11&&key_1<=13)
				break; }
			}

		switch (key_1)
		{

      case 11:
			{
				unsigned char page=1;
				while (1)
				{
					switch (page)
					{
						case 1:
							{
							key=00;
							KeyIO=0xf0;
							Ini_Lcd();//Һ����ʼ���ӳ���
								Disp(1,0,8,"����Ŀ¼");//��ʾ���ݵ�LCD12864�ӳ���			
							Disp(2,0,10,"1.ǧ��ǧѰ");//��ʾ���ݵ�LCD12864�ӳ���
							Disp(3,0,8,"2.��ӹ�");//��ʾ���ݵ�LCD12864�ӳ���
							Disp(4,0,8,"4.��һҳ");//��ʾ���ݵ�LCD12864�ӳ���
							while (1)
							{
								if ((KeyIO&0xf0)!=0xf0)
							{
								Delay_xMs(100);
								if ((KeyIO&0xf0)!=0xf0)
								{
								key=scankey();
                                if (key==11||key==12||key==14||key==43)
								break;	
								}
							}	
							}
							switch (key)
							{
							case 11:
								Ini_Lcd();
								Disp(1,0,8,"ǧ��ǧѰ");
						  	Disp(4,0,8,"16���˳�");
								play_start(music1); 
								break;//��ʾ���ݵ�LCD12864�ӳ���
							case 12:
								Ini_Lcd();
								Disp(1,0,6,"��ӹ�");
						  	Disp(4,0,8,"16���˳�");
								play_start(music2);	
								break;//��ʾ���ݵ�LCD12864�ӳ�
							case 14:
								page=2;
								break;
							default: break;
							}
							break;
							}
						case 2:
							{
							key=00;
							KeyIO=0xf0;
							Ini_Lcd();//Һ����ʼ���ӳ���
							Disp(1,0,14,"��ѡ�񲥷Ÿ���");//��ʾ���ݵ�LCD12864�ӳ���			
							Disp(2,0,10,"1.���֮��");//��ʾ���ݵ�LCD12864�ӳ���
							Disp(3,0,6,"2.¼��");//��ʾ���ݵ�LCD12864�ӳ���
							Disp(4,0,8,"3.��һҳ");//��ʾ���ݵ�LCD12864�ӳ���
							while (1)
							{
								if ((KeyIO&0xf0)!=0xf0)
								{
									Delay_xMs(100);
									if ((KeyIO&0xf0)!=0xf0)
									{
										key=scankey();
                                        if (key==11||key==12||key==13||key==43)	
										break;
									}
								}
							}
							switch (key)
							{
							case 11:
								Ini_Lcd();
								Disp(1,0,8,"���֮��");
						  	Disp(4,0,8,"16���˳�");
								play_start(music3); 
								break;//��ʾ���ݵ�LCD12864�ӳ���
							case 12:
                                if (music6[1][0]==0)
                                {
                                Ini_Lcd();
                                Disp(4,0,8,"16���˳�");
                                Disp(4,5,6,"����Ƶ");
                                KeyIO=0xf0;
                                while (1)
                                {
                                    if ((P1&0xf0)!=0xf0)
                					{
                						Delay_xMs(50);
                					 	if ((P1&0xf0)!=0xf0)
                					 	{
                                        if (scankey()==44)
                                        break;
                                        }
                					}
                                }
                                break;
    							}
								Ini_Lcd();
								Disp(4,5,6,"������");
						  	    Disp(4,0,8,"16���˳�");
								play_start(music6);	
								break;//��ʾ���ݵ�LCD12864�ӳ�
							case 13:
								page=1;
								break;
							default: break;
							} 
							break;
							}
							default: break;
					}
					if (key==43)
					break;
				}
				break;
			}
			case 12:
			{   
				
                bit flag=0;
                Ini_Lcd();
				play_judge = 1;
				//Disp(1,0,12,"���е���ģʽ");//��ʾ���ݵ�LCD12864�ӳ���
				//Disp(4,0,12,"1.¼2.ͣ3.��");//��ʾ���ݵ�LCD12864�ӳ���
				Disp(3,0,12,"1.¼��2.��ͣ");//��ʾ���ݵ�LCD12864�ӳ���
				Disp(4,0,10,"3.�طŶԱ�");
			  	while (1)
			  	{
			  		char tune=0;
					key=00;
					KeyIO=0xf0;
					if ((P1&0xf0)!=0xf0)
			  		{
				  		Delay_xMs(100);
						if ((P1&0xf0)!=0xf0)
						key=scankey();	
					} 
                    switch(key)
			  		{
			  			case 11:
							Disp(2,0,8,"¼������");
							k=1;i=0;
							break;//��ʾ���ݵ�LCD12864�ӳ���	
			  			case 12:
			  				Disp(2,0,8,"¼���ر�");
							k=0;
                            flag=0;
                            music6[i][0]=0xff;
							music6[i][1]=0xff;
                            i=0;
							break;//��ʾ���ݵ�LCD12864�ӳ���
						case 13:
                            if (music6[1][0]==0)
                            {
                            Disp(3,0,6,"����Ƶ");
                            break;
							}
                            //show_score(music0);
                            Ini_Lcd();
                            Disp(1,6,4,"�ط�");
														Disp(3,6,4,"ԭ��");
							play_start(music6+1);
                            Ini_Lcd();
                            //Disp(1,0,12,"���е���ģʽ");//��ʾ���ݵ�LCD12864�ӳ���
				            Disp(3,0,12,"1.¼��2.��ͣ");//��ʾ���ݵ�LCD12864�ӳ���
										Disp(4,0,10,"3.�طŶԱ�");
							break;//��ʾ���ݵ�LCD12864�ӳ���
					}
					key_tune=00;
					KeyIO=0xf0;
					if ((P1&0xf0)!=0xf0)
					{
						Delay_xMs(50);
					 	if ((P1&0xf0)!=0xf0)
					 	key_tune=scankey();
					}
					if (OPT_CHECK!=0x00)
						  {
							switch(key_tune)
							{
							case 41:
							Disp(1,6,4,"����");
							tune=1;
							break;
							case 42:
							Disp(1,6,4,"����");
							tune=-1;
							break;
                            default:
                            Disp(1,6,4,"����");
							tune=0;
							break;
							}	
						 }
		  				if(OPT_CHECK&0x01)
						 {
						    Disp(1,0,8,"������1");
							 m=13+12*tune,n=2;
							 
						 }
						 else if(OPT_CHECK&0x02)
						 {
						   Disp(1,0,8,"������2");
							 m=15+12*tune,n=2;
							 
						 }
						 else if(OPT_CHECK&0x04)
						 {
						   Disp(1,0,8,"������3");
							 m=17+12*tune,n=2;
							 
						 }
						 else if(OPT_CHECK&0x08)
						 {
						   Disp(1,0,8,"������4");
							 m=18+12*tune,n=2;
							 
						 }
						 else if(OPT_CHECK&0x10)
						 {
						  Disp(1,0,8,"������5");
							 m=20+12*tune,n=2;
							
						 }
						 else if(OPT_CHECK&0x20)
						 {
						   Disp(1,0,8,"������6");
							 m=22+12*tune,n=2;
							 
						 }
						 else if(OPT_CHECK&0x40)
						 {
						   Disp(1,0,8,"������7");
							 m=24+12*tune,n=2;
						 }
						 else{
						 	m=0,n=2;
							TR0=0;
						 	Disp(1,0,8,"������0");
						 }
                         if (k==1&&flag==0)
                         {
                         if (m!=0)
                         flag=1;
                         for (i=0;i++;i<60)
                         {
                         music6[i][0]=0;
                         music6[i][1]=0;
                         }
                         i=1;
                         }
						 if(k==1&&flag==1){
                         if (music6[i-1][0]==m&&music6[i-1][1]==4)
                         music6[i-1][1]=music6[i-1][1]+4;
                         else
                         {
                         music6[i][0]=m;
												 music6[i][1]=n*2;
                         i++;
                         }
						 }
						 if(i>=61){
						 	music6[i][0]=0xFF;
							music6[i][1]=0xFF;
							i=0;k=0;flag=0;
							Disp(2,0,8,"¼���ر�");
						 } 
						 if(m==0)
							{
							TR0=0;
							delay(n);}
						 else
						 	{
							 TR0=1;
							 delay(n);
							}
						if (key==43)
                        {
                            TR0=0;
                            break;
                        }
						
			  	}
					play_judge = 0;
			  	break;
			}
       case 13:
		{  
            char key_game;
            while (1)
            {
                key_game=00;
                Ini_Lcd();
								Disp(1,0,10,"1:���׵���");
                Disp(2,0,10,"2:�����ʦ");
                Disp(4,0,8,"15���˳�");
                while (1)
                {
                    KeyIO=0xf0;
                    if ((KeyIO&0xf0)!=0xf0)
                    {
                        Delay_xMs(100);
                        if ((KeyIO&0xf0)!=0xf0)
                        {
                            key_game=scankey();
                            if (key_game==11||key_game==12||key_game==43)
                            break;
                        }
                    }
                }
                if (key_game==43)
                    break;
                switch (key_game)
                {
                case 11:
                {
                while(1)
                {
    			char flag2=1,flag=1,mm,nn,sum,check,choice;
					check=0;
					sum=0;
    			Ini_Lcd();	
    			Disp(1,0,8,"���׵���");
    			Disp(2,0,8,"1:��ӹ�");
    			Disp(3,0,10,"2:ǧ��ǧѰ");
                Disp(4,0,8,"15���˳�");
    			key=00;
    		    KeyIO=0xf0;
                while (1)
    			{
    				if ((KeyIO&0xf0)!=0xf0)
    					{
    					Delay_xMs(100);
    					if ((KeyIO&0xf0)!=0xf0)
    					{
    						key=scankey();	
    						if (key==43||key==11||key==12)
    						break;
    						}
    					}
    			}
                if (key==43)
                {
                TR0=0;
                break;
                }
    				switch(key){
    					case 11:
    						flag2=0;
    						choice=1;
    					  break;	
    					case 12:
    						flag2=0;
    						choice=2;
    					  break;
    					default: break;
    				}
    			//sum=0;
    			if(flag2==0){
    				Ini_Lcd();
    			for(i=1;;i++)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               {
    				char tune=0;
    				sum++;
    				flag=1;
    				if(choice==1)
    					mm=music2[i][0];
    				else if(choice==2)
    					mm=music1[i][0];
    				if(mm==13) Disp(2,0,14,"ԭ�ף�do  ����");
    				else if(mm==15) Disp(2,0,14,"ԭ�ף�re  ����");
    				else if(mm==17) Disp(2,0,14,"ԭ�ף�mi  ����");
    				else if(mm==18) Disp(2,0,14,"ԭ�ף�fa  ����");
    				else if(mm==20) Disp(2,0,14,"ԭ�ף�so  ����");
    				else if(mm==22) Disp(2,0,14,"ԭ�ף�la  ����");
    				else if(mm==24) Disp(2,0,14,"ԭ�ף�si  ����");
    				
    				else if(mm==1) Disp(2,0,14,"ԭ�ף�do  ����");
    				else if(mm==3) Disp(2,0,14,"ԭ�ף�re  ����");
    				else if(mm==5) Disp(2,0,14,"ԭ�ף�mi  ����");
    				else if(mm==6) Disp(2,0,14,"ԭ�ף�fa  ����");
    				else if(mm==8) Disp(2,0,14,"ԭ�ף�so  ����");
    				else if(mm==10) Disp(2,0,14,"ԭ�ף�la  ����");
    				else if(mm==12) Disp(2,0,14,"ԭ�ף�si  ����");
    				
    				else if(mm==25) Disp(2,0,14,"ԭ�ף�do  ����");
    				else if(mm==27) Disp(2,0,14,"ԭ�ף�re  ����");
    				else if(mm==29) Disp(2,0,14,"ԭ�ף�mi  ����");
    				else if(mm==30) Disp(2,0,14,"ԭ�ף�fa  ����");
    				else if(mm==32) Disp(2,0,14,"ԭ�ף�so  ����");
    				else if(mm==34) Disp(2,0,14,"ԭ�ף�la  ����");
    				else if(mm==36) Disp(2,0,14,"ԭ�ף�si  ����");
    				
    				else if(mm==0) {
                        TR0=0;
    					flag2=1;break;
    				}
    				//++++++++++++++++++++++++++++++++++++++++++++++++
    					while(flag==1){
    				    key_tune=00;
    					KeyIO=0xf0;
    					if ((P1&0xf0)!=0xf0)
    					{
    						Delay_xMs(50);
    					 	if ((P1&0xf0)!=0xf0)
    					 	key_tune=scankey();
    					}
    					if (OPT_CHECK!=0x00)
    						{
    							switch(key_tune)
    							{
    							case 41:
    							Disp(3,5,4,"����");
    							tune=1;
    							break;
    							case 42:
    							Disp(3,5,4,"����");
    							tune=-1;
    							break;
                                default:
                                Disp(3,5,4,"����");
    							tune=0;
    							break;
    							}	
    						 }
                        if (key_tune==44)
                        {
                        TR0=0;
                        break;
                        }
                        
    				
    				//++++++++++++++++++++++++++++++++++++++++++++++++
    				
    			       // while(flag==1){
    				if(OPT_CHECK&0x01)
    				 {
    				    Disp(3,0,8,"�ڵ���do");
    					  nn=13+12*tune;flag=0;
    					 m=13+12*tune,n=8;
    				 }
    				 else if(OPT_CHECK&0x02)
    				 {
    				   Disp(3,0,8,"�ڵ���re");
    					 nn=15+12*tune;flag=0;
    					 m=15+12*tune,n=8;
    				 }
    				 else if(OPT_CHECK&0x04)
    				 {
    				   Disp(3,0,8,"�ڵ���mi");
    					 nn=17+12*tune;flag=0;
    					 m=17+12*tune,n=8;
    				 }
    				 else if(OPT_CHECK&0x08)
    				 {
    				   Disp(3,0,8,"�ڵ���fa");
    					 nn=18+12*tune;flag=0;
    					 m=18+12*tune,n=8;
    				 }
    				 else if(OPT_CHECK&0x10)
    				 {
    				  Disp(3,0,8,"�ڵ���so");
    					 nn=20+12*tune;flag=0;
    					 m=20+12*tune,n=8;
    				 }
    				 else if(OPT_CHECK&0x20)
    				 {
    				   Disp(3,0,8,"�ڵ���la");
    					 nn=22+12*tune;flag=0;
    					 m=22+12*tune,n=8;
    				 }
    				 else if(OPT_CHECK&0x40)
    				 {
    				   Disp(3,0,8,"�ڵ���si");
    					 nn=24+12*tune;flag=0;
    					 m=24+12*tune,n=8;
    				 }
    				 else{
    				   nn=0;m=0,n=2;
    				 	 Disp(3,0,8,"�ڵ���0");
    				 }
    				 if(m==0x00)
            			 {TR0=0;delay(n);} 
            			 else
            			 {TR0=1;delay(n);}
    			 }
                 if (key_tune==44)
                 {
                 TR0=0;
                 break;
                 }
    			 Delay_xMs(2000);
    			 if(mm==nn) check++;
    			 //if(i==42) flag2=1;
    			}
    		  }
    			if(check==1) Disp(4,0,8,"�÷�:1��");
					else if(check==2) Disp(4,0,8,"�÷�:2��");
    			else if(check==3) Disp(4,0,8,"�÷�:3��");
					else if(check==4) Disp(4,0,8,"�÷�:4��");
    			else if(check==5) Disp(4,0,8,"�÷�:5��");
					else if(check==6) Disp(4,0,8,"�÷�:6��");
					else if(check==7) Disp(4,0,8,"�÷�:7��");
					else if(check==8) Disp(4,0,8,"�÷�:8��");
					else if(check==9) Disp(4,0,8,"�÷�:9��");
    			else if(check>=10) Disp(4,0,10,"�÷֣�10��");
					else Disp(4,0,8,"�÷�:0��");
    			check=0;
    			sum=0;
                //Disp(1,0,6,"1.����");
                delay(50);
                KeyIO=0xf0;
                while (1)
    			{
    				if ((KeyIO&0xf0)!=0xf0)
                    {
    				Delay_xMs(100);
    				if((KeyIO&0xf0)!=0xf0)
    				break; 
                    }
    			} 
          
    		}
            break;
            }
    case 12:
		{
			while(1)
			{
				Ini_Lcd();
				i_cide=0;
				Disp(1,0,8,"�����ʦ");
				Disp(2,0,8,"�Ѷ�1-10");
				Disp(3,0,16,"�Ѷȸ��ٶȿ�ָ�");
				Disp(4,0,8,"15���˳�");
				for(i=0;i<5;i++)
				{
					cide[i]=0+0x30;
				}
				key = 00;
				KeyIO = 0xf0;
				while(1)
				{
					if ((KeyIO&0xf0)!=0xf0)
					{
							Delay_xMs(100);
							if ((KeyIO&0xf0)!=0xf0)
							{
								key=scankey();	
								if (key==43||key>=11||key<=32)
									break; //�������̵�ѭ��
							}
					}
				}//�жϵ�ѭ��
				
				if(key==43)
					break; //����case12��ѭ��
				
				Ini_Lcd();
				game2_number = rand()%5;
				Disp(1,0,6,game2_num[game2_number]);
				switch(key){
					case 11:
						delay(11);
						grade=1;
						break;
					case 12:
						delay(10);
						grade=2;
						break;
					case 13:
						delay(9);
						grade=3;
						break;
					case 14:
						delay(8);
						grade=4;
						break;
					case 21:
						delay(7);
						grade=5;
						break;
					case 22:
						delay(6);
						grade=6;
						break;
					case 23:
						delay(5);
						grade=7;
						break;
					case 24:
						delay(4);
						grade=8;
						break;
					case 31:
						delay(3);
						grade=9;
						break;
					case 32:
						delay(2);
						grade=10;
						break;
				}
				Ini_Lcd(); //ˢ��
				TMOD = 0x10;
				TH1 = 0x3c;
				TL1 = 0xb0;
				EA = 1;
				ET1 = 1;
				TR1 = 1;
				for (i=0;i<5;i++)
				{
					Write_Cmd(0x88+i);
					Write_Data(0x00);
					Write_Data(0x00);
				}
				
				Write_Cmd(0x88+i_cide);
				Write_Data(0x00);
				Write_Data(0x02);
				
				while(1)
				{
					bit flag_cide;
					flag_cide=0;
					key_cide=00;
					while (1)
					{
						KeyIO=0xf0;
						if((KeyIO&0xf0)!=0xf0)
						{
							Delay_xMs(100);
							if ((KeyIO&0xf0)!=0xf0)
							{
								key_cide=scankey();
								KeyIO=0xf0;
								while (KeyIO!=0xf0);
									break;
							}
						}
					}//ѡ����̵�ѭ��
					
					switch (key_cide)
					{
						case 11:
            cide[i_cide]=1+0x30;
            break;
            case 12:
            cide[i_cide]=2+0x30;
            break;
            case 13:
            cide[i_cide]=3+0x30;
            break;
            case 14:
            cide[i_cide]=4+0x30;
            break;
            case 21:
            cide[i_cide]=5+0x30;
            break;
            case 22:
            cide[i_cide]=6+0x30;
            break;
            case 23:
            cide[i_cide]=7+0x30;
            break;
            case 24:
            cide[i_cide]=8+0x30;
            break;
            case 31:
            cide[i_cide]=9+0x30;
            break;
            default:
            if (i_cide)
            {
            if (i_cide<4||cide[4]==0x30)
            {
							i_cide--;
							cide[i_cide]=0+0x30;
            }
            else
              cide[i_cide]=0+0x30;
            }
            break;
					}//switch��ѭ��
					if (i_cide<4&&key_cide<32)
						i_cide++;
					for (i=0;i<5;i++)
					{
						if (cide[i]-0x30)
            Disp(2,i,1,cide+i);
            else
            Disp(2,i,2," ");
					}//forѭ��
					for (i=0;i<5;i++)
					{
						Write_Cmd(0x88+i);
						Write_Data(0x00);
						Write_Data(0x00);
					}//forѭ��
					
					Write_Cmd(0x88+i_cide);
					Write_Data(0x00);
					Write_Data(0x02);
					
					if(cide[4]!=0x30)
					{
						flag_cide=1;
						for (i=0;i<5;i++)
						{
							if ((cide[i]-0x30)!=game2_check[game2_number][i])
							{
								flag_cide=0;
								
						Disp(1,0,12,"�ܿ�ϧʧ����");
						Disp(4,0,8,"15���˳�");
						while(1)
						{
							if ((KeyIO&0xf0)!=0xf0)
							{
								Delay_xMs(100);
								if ((KeyIO&0xf0)!=0xf0)
								{
									key=scankey();	
									if (key==43)
										break; //�������̵�ѭ��
								}
							}	
						}//�жϵ�ѭ��
						if(key==43)
							break;
						  }
						}
						if(key==43)
							break;
					}
					if (flag_cide)
					{
						TR1 = 0;
						Ini_Lcd();
						Disp(1,0,12,"��ϲ��ɹ���");
						if(time<=100)
							grade+=30;
						else if(time<=200)
							grade+=25;
						else
							grade+=20;
						temp[0] = grade/10+0x30;
						temp[1] = grade%10+0x30;
						temp[2] = '\0';
						Disp(2,0,6,"�÷֣�");
						Disp(2,4,2,temp);
						Disp(4,0,8,"15���˳�");
						while(1)
						{
							if ((KeyIO&0xf0)!=0xf0)
							{
								Delay_xMs(100);
								if ((KeyIO&0xf0)!=0xf0)
								{
									key=scankey();	
									if (key==43)
										break; //�������̵�ѭ��
								}
							}	
						}//�жϵ�ѭ��
						if(key==43)
							break;
					}
					
				}//Сѭ��
			}//case12��ѭ��
			break;
		}//case12�Ĵ�ѭ��
            default: break;
            }   
        }		
      	break;	 
		default: break;
		}
	}   //switch(key_1)
    }   //while(1)
}   //void main

/*****************�����ƶ˿ڵ�״̬*****************/
uchar ctrl_port_check(void)
{
		SW_CTRL = 0xFF;
		return 	SW_CTRL&0xF0;
}


	 
/****************�ӳٺ�����************************/
void Delay_xMs(unsigned int x)
{
    unsigned int i,j;
    for( i =0;i < x;i++ )
    {
        for( j =0;j<2;j++ );
    }
}


void delay(uchar p)
{
	uchar i,j; 
	p = p*10;
	for(;p>0;p--)
	for(i=181;i>0;i--)
	for(j=181;j>0;j--);
}
void pause()
{
	uchar i,j;
	for(i=150;i>0;i--)
	for(j=150;j>0;j--);
}
void T0_int() interrupt 1
{
	bee_Speak=!bee_Speak;
	TH0=T[m][0]; 
	TL0=T[m][1];
}
void T1_int() interrupt 3
{
	TH1 = 0x3c;
	TL0 = 0xb0;
	time++;
}

void play_start(uchar (*music)[2])
{
    uchar i=0,ii=0; 
		uchar j,p=2;
    char xdata score[70][4]={0}; //score�ĵ�һ��ά����tune���ڶ���ά����num��������ά����n�����ĸ�ά����m
    char tune,num;
    TMOD=0x01; EA=1; ET0=1; 
    if (start==1)
    {
    while (1)
    {
    m=music[i][0];
    n=music[i][1];
    if(m==0x00)
	{
		TR0=0;delay(n);i++;
	} 
	else if(m==0xFF)
	{
		TR0=0;
		return;
	} 
	else
	{
		TR0=1;
		delay(n);
		i++;
	}
    }
    }
    //get score information
            while(1)
            {
							m=music[i][0];
							n=music[i][1];
							score[ii][3]=m;
            if (m==0||(m>=13&&m<=24))
							tune=0;
            else if (m>0&&m<13)
							tune=-1;
            else if (m>24&&m<=36)
							tune=1;
            else
							tune=2;
							score[ii][0]=tune;
            if (tune==2)
							break;
							num=m-12*tune;
            switch (num)
            {
                case 13:
                case 14:
                score[ii][1]=1; break;
                case 15:
                case 16:
                score[ii][1]=2; break;
                case 17:score[ii][1]=3; break;
                case 18:
                case 19:
                score[ii][1]=4; break;
                case 20:
                case 21:
                score[ii][1]=5; break;
                case 22:
                case 23:
                score[ii][1]=6; break;
                case 24:score[ii][1]=7; break;
                case 0:score[ii][1]=0;  break;
            }
            score[ii][2]=n;
            ii++;
            i++;
            }
        i=0;
	while(1) 
	{
		if((P1&0xf0)!=0xf0) //����м�����
    	{
			Delay_xMs(100);   //��ʱȥ����
			if((KeyIO&0xf0)!=0xf0)   //���ж�
			{
				key=scankey();
			    if(key==44){
					TR0=0;
      			    return;
	   			}
			}
		}   
				
		num=score[i][1];
        tune=score[i][0];
        n=score[i][2];
		//��ʾ����
		
            if (tune==2)
            {
            TR0=0;
            break;
            }
			j=i%8;
		if(play_judge)
		{
			switch (tune)
            {
                case -1:
                {
                    switch (num)
                    {
                        case 1: Disp(p+2,j,2,"1"); break;
                        case 2: Disp(p+2,j,2,"2"); break;
                        case 3: Disp(p+2,j,2,"3"); break;
                        case 4: Disp(p+2,j,2,"4"); break;
                        case 5: Disp(p+2,j,2,"5"); break;
                        case 6: Disp(p+2,j,2,"6"); break;
                        case 7: Disp(p+2,j,2,"7"); break;
                        
                    }
                    switch (n)
                    {
                        case 2: 
                        Write_Cmd(0x88+j);
                        Write_Data(0x00);
                        Write_Data(0x06);
                        break;
                        case 4:
                        Write_Cmd(0x88+j);
                        Write_Data(0x00);
                        Write_Data(0x04);
                        break;
                        case 8:
                        Disp(p+1,j,1,&dot_l);
                        break;
                    }
                    break;
                }
                case 0:
                {
                    switch (num)
                    {
                        case 0: Disp(p+2,j,2,"0"); break;
                        case 1: Disp(p+2,j,2,"1"); break;
                        case 2: Disp(p+2,j,2,"2"); break;
                        case 3: Disp(p+2,j,2,"3"); break;
                        case 4: Disp(p+2,j,2,"4"); break;
                        case 5: Disp(p+2,j,2,"5"); break;
                        case 6: Disp(p+2,j,2,"6"); break;
                        case 7: Disp(p+2,j,2,"7"); break;
                    }
                    switch (n)
                    {
                        case 2: 
                        Write_Cmd(0x88+j);
                        Write_Data(0x00);
                        Write_Data(0x02);
                        break;
                        case 4:
                        Write_Cmd(0x88+j);
                        Write_Data(0x00);
                        Write_Data(0x00);
                        break;
                        case 8:
                        break;
                    }
                    break;
                }
                case 1:
                {
                    switch (num)
                    {
                        case 1: Disp(p+2,j,2,"1"); break;
                        case 2: Disp(p+2,j,2,"2"); break;
                        case 3: Disp(p+2,j,2,"3"); break;
                        case 4: Disp(p+2,j,2,"4"); break;
                        case 5: Disp(p+2,j,2,"5"); break;
                        case 6: Disp(p+2,j,2,"6"); break;
                        case 7: Disp(p+2,j,2,"7"); break;
                    }
                    switch (n)
                    {
                        case 2: 
                        Write_Cmd(0x88+j);
                        Write_Data(0x00);
                        Write_Data(0x02);
                        Disp(p-1,j,1,&dot_h);
                        break;
                        case 4:
                        Write_Cmd(0x88+j);
                        Write_Data(0x00);
                        Write_Data(0x00);
                        Disp(p-1,j,1,&dot_h);
                        break;
                        case 8:
                        Disp(p-1,j,1,&dot_h);
                        break;
                    }
                    Disp(p-1,j,1,&dot_h);
                    break;
                }
            }
		}

            switch (tune)
            {
                case -1:
                {
                    switch (num)
                    {
                        case 1: Disp(p,j,2,"1"); break;
                        case 2: Disp(p,j,2,"2"); break;
                        case 3: Disp(p,j,2,"3"); break;
                        case 4: Disp(p,j,2,"4"); break;
                        case 5: Disp(p,j,2,"5"); break;
                        case 6: Disp(p,j,2,"6"); break;
                        case 7: Disp(p,j,2,"7"); break;
                        
                    }
                    switch (n)
                    {
                        case 2: 
                        Write_Cmd(0x88+j);
                        Write_Data(0x00);
                        Write_Data(0x06);
                        break;
                        case 4:
                        Write_Cmd(0x88+j);
                        Write_Data(0x00);
                        Write_Data(0x04);
                        break;
                        case 8:
                        Disp(p+1,j,1,&dot_l);
                        break;
                    }
                    break;
                }
                case 0:
                {
                    switch (num)
                    {
                        case 0: Disp(p,j,2,"0"); break;
                        case 1: Disp(p,j,2,"1"); break;
                        case 2: Disp(p,j,2,"2"); break;
                        case 3: Disp(p,j,2,"3"); break;
                        case 4: Disp(p,j,2,"4"); break;
                        case 5: Disp(p,j,2,"5"); break;
                        case 6: Disp(p,j,2,"6"); break;
                        case 7: Disp(p,j,2,"7"); break;
                    }
                    switch (n)
                    {
                        case 2: 
                        Write_Cmd(0x88+j);
                        Write_Data(0x00);
                        Write_Data(0x02);
                        break;
                        case 4:
                        Write_Cmd(0x88+j);
                        Write_Data(0x00);
                        Write_Data(0x00);
                        break;
                        case 8:
                        break;
                    }
                    break;
                }
                case 1:
                {
                    switch (num)
                    {
                        case 1: Disp(p,j,2,"1"); break;
                        case 2: Disp(p,j,2,"2"); break;
                        case 3: Disp(p,j,2,"3"); break;
                        case 4: Disp(p,j,2,"4"); break;
                        case 5: Disp(p,j,2,"5"); break;
                        case 6: Disp(p,j,2,"6"); break;
                        case 7: Disp(p,j,2,"7"); break;
                    }
                    switch (n)
                    {
                        case 2: 
                        Write_Cmd(0x88+j);
                        Write_Data(0x00);
                        Write_Data(0x02);
                        Disp(p-1,j,1,&dot_h);
                        break;
                        case 4:
                        Write_Cmd(0x88+j);
                        Write_Data(0x00);
                        Write_Data(0x00);
                        Disp(p-1,j,1,&dot_h);
                        break;
                        case 8:
                        Disp(p-1,j,1,&dot_h);
                        break;
                    }
                    Disp(p-1,j,1,&dot_h);
                    break;
                }
            }

			if(j==7){
				p++;
				//if(p==4) {
                if (p==3)  {
					//p=1;
                    p=2;
					Ini_Lcd();
					Disp(4,0,8,"16���˳�");
				}
			}	
	    	//�ų�������ʾ����
        if (num==0)
        {
              TR0=0;
              delay(score[i][2]);
        }	
        else 
        {
            TR0=1;
            m=score[i][3];
            delay(score[i][2]);
        }
        i++;
	}
    TR0=0;
}

uchar scankey(void)//������̷�תɨ��
{
	uint keyvalue=0;
	uchar temp1,temp2,keycode;

	KeyIO=0xf0;		//����0����1
	temp1=KeyIO&0xf0;
	if((temp1&0xf0)==0xf0) return(0);  //���޼����·���0
	KeyIO=0x0f;
	temp2=KeyIO&0x0f;					   //���м����£�����1����0
	keycode=~(temp1|temp2);			   //��ü�����
	switch(keycode)					   //���ݼ����뷵�ؼ�ֵ
	{
		case 0x11:return(11);break;
		case 0x21:return(12);break;
		case 0x41:return(13);break;
		case 0x81:return(14);break;
		case 0x12:return(21);break;
		case 0x22:return(22);break;
		case 0x42:return(23);break;
		case 0x82:return(24);break;
		case 0x14:return(31);break;
		case 0x24:return(32);break;
		case 0x44:return(33);break;
		case 0x84:return(34);break;
		case 0x18:return(41);break;
		case 0x28:return(42);break;
		case 0x48:return(43);break;
		case 0x88:return(44);break;
		default:  return(0);break;
	}
	return(0);
}