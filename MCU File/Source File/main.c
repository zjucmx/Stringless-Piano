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
	Ini_Lcd();//液晶初始化子程序
	WRGDRAM(0x80,clong,hight,gImage_1);//求是之光
	play_start(music0);		
	P4M1=0x00;
	P4M0=0x00;
	Ini_Lcd();//液晶初始化子程序
	WRCGRAM1(0x40);
	WRCGRAM2(0x50);
	WRCGRAM3(0x60);
	WRCGRAM4(0x70);
	Disp(1,0,16,"浙江大学光电学院");//显示数据到LCD12864子程序			
	Disp(2,1,14,"电子系统设计");//显示数据到LCD12864子程序
	Disp(3,1,12,"from：蔡明轩");//显示数据到LCD12864子程序
	Disp(4,1,12,"n:3180101484");//显示数据到LCD12864子程序
	delay(20);
	start=0;	
	Ini_Lcd();
    Disp(1,3,4,"密码");
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
		Ini_Lcd();//液晶初始化子程序			
		Disp(1,0,8,"菜单界面");//显示数据到LCD12864子程序
		Disp(2,0,10,"1.歌曲选择");//显示数据到LCD12864子程序
		Disp(3,0,10,"2.基本弹奏");//显示数据到LCD12864子程序
		Disp(4,0,10,"3.游戏模块");//显示数据到LCD12864子程序
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
							Ini_Lcd();//液晶初始化子程序
								Disp(1,0,8,"歌曲目录");//显示数据到LCD12864子程序			
							Disp(2,0,10,"1.千与千寻");//显示数据到LCD12864子程序
							Disp(3,0,8,"2.红河谷");//显示数据到LCD12864子程序
							Disp(4,0,8,"4.下一页");//显示数据到LCD12864子程序
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
								Disp(1,0,8,"千与千寻");
						  	Disp(4,0,8,"16：退出");
								play_start(music1); 
								break;//显示数据到LCD12864子程序
							case 12:
								Ini_Lcd();
								Disp(1,0,6,"红河谷");
						  	Disp(4,0,8,"16：退出");
								play_start(music2);	
								break;//显示数据到LCD12864子程
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
							Ini_Lcd();//液晶初始化子程序
							Disp(1,0,14,"请选择播放歌曲");//显示数据到LCD12864子程序			
							Disp(2,0,10,"1.天空之城");//显示数据到LCD12864子程序
							Disp(3,0,6,"2.录音");//显示数据到LCD12864子程序
							Disp(4,0,8,"3.上一页");//显示数据到LCD12864子程序
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
								Disp(1,0,8,"天空之城");
						  	Disp(4,0,8,"16：退出");
								play_start(music3); 
								break;//显示数据到LCD12864子程序
							case 12:
                                if (music6[1][0]==0)
                                {
                                Ini_Lcd();
                                Disp(4,0,8,"16：退出");
                                Disp(4,5,6,"无音频");
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
								Disp(4,5,6,"播放中");
						  	    Disp(4,0,8,"16：退出");
								play_start(music6);	
								break;//显示数据到LCD12864子程
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
				//Disp(1,0,12,"进行弹奏模式");//显示数据到LCD12864子程序
				//Disp(4,0,12,"1.录2.停3.放");//显示数据到LCD12864子程序
				Disp(3,0,12,"1.录音2.暂停");//显示数据到LCD12864子程序
				Disp(4,0,10,"3.回放对比");
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
							Disp(2,0,8,"录音开启");
							k=1;i=0;
							break;//显示数据到LCD12864子程序	
			  			case 12:
			  				Disp(2,0,8,"录音关闭");
							k=0;
                            flag=0;
                            music6[i][0]=0xff;
							music6[i][1]=0xff;
                            i=0;
							break;//显示数据到LCD12864子程序
						case 13:
                            if (music6[1][0]==0)
                            {
                            Disp(3,0,6,"无音频");
                            break;
							}
                            //show_score(music0);
                            Ini_Lcd();
                            Disp(1,6,4,"回放");
														Disp(3,6,4,"原音");
							play_start(music6+1);
                            Ini_Lcd();
                            //Disp(1,0,12,"进行弹奏模式");//显示数据到LCD12864子程序
				            Disp(3,0,12,"1.录音2.暂停");//显示数据到LCD12864子程序
										Disp(4,0,10,"3.回放对比");
							break;//显示数据到LCD12864子程序
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
							Disp(1,6,4,"高音");
							tune=1;
							break;
							case 42:
							Disp(1,6,4,"低音");
							tune=-1;
							break;
                            default:
                            Disp(1,6,4,"中音");
							tune=0;
							break;
							}	
						 }
		  				if(OPT_CHECK&0x01)
						 {
						    Disp(1,0,8,"音符：1");
							 m=13+12*tune,n=2;
							 
						 }
						 else if(OPT_CHECK&0x02)
						 {
						   Disp(1,0,8,"音符：2");
							 m=15+12*tune,n=2;
							 
						 }
						 else if(OPT_CHECK&0x04)
						 {
						   Disp(1,0,8,"音符：3");
							 m=17+12*tune,n=2;
							 
						 }
						 else if(OPT_CHECK&0x08)
						 {
						   Disp(1,0,8,"音符：4");
							 m=18+12*tune,n=2;
							 
						 }
						 else if(OPT_CHECK&0x10)
						 {
						  Disp(1,0,8,"音符：5");
							 m=20+12*tune,n=2;
							
						 }
						 else if(OPT_CHECK&0x20)
						 {
						   Disp(1,0,8,"音符：6");
							 m=22+12*tune,n=2;
							 
						 }
						 else if(OPT_CHECK&0x40)
						 {
						   Disp(1,0,8,"音符：7");
							 m=24+12*tune,n=2;
						 }
						 else{
						 	m=0,n=2;
							TR0=0;
						 	Disp(1,0,8,"音符：0");
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
							Disp(2,0,8,"录音关闭");
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
								Disp(1,0,10,"1:看谱弹曲");
                Disp(2,0,10,"2:记忆大师");
                Disp(4,0,8,"15：退出");
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
    			Disp(1,0,8,"看谱弹曲");
    			Disp(2,0,8,"1:红河谷");
    			Disp(3,0,10,"2:千与千寻");
                Disp(4,0,8,"15：退出");
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
    				if(mm==13) Disp(2,0,14,"原谱：do  中音");
    				else if(mm==15) Disp(2,0,14,"原谱：re  中音");
    				else if(mm==17) Disp(2,0,14,"原谱：mi  中音");
    				else if(mm==18) Disp(2,0,14,"原谱：fa  中音");
    				else if(mm==20) Disp(2,0,14,"原谱：so  中音");
    				else if(mm==22) Disp(2,0,14,"原谱：la  中音");
    				else if(mm==24) Disp(2,0,14,"原谱：si  中音");
    				
    				else if(mm==1) Disp(2,0,14,"原谱：do  低音");
    				else if(mm==3) Disp(2,0,14,"原谱：re  低音");
    				else if(mm==5) Disp(2,0,14,"原谱：mi  低音");
    				else if(mm==6) Disp(2,0,14,"原谱：fa  低音");
    				else if(mm==8) Disp(2,0,14,"原谱：so  低音");
    				else if(mm==10) Disp(2,0,14,"原谱：la  低音");
    				else if(mm==12) Disp(2,0,14,"原谱：si  低音");
    				
    				else if(mm==25) Disp(2,0,14,"原谱：do  高音");
    				else if(mm==27) Disp(2,0,14,"原谱：re  高音");
    				else if(mm==29) Disp(2,0,14,"原谱：mi  高音");
    				else if(mm==30) Disp(2,0,14,"原谱：fa  高音");
    				else if(mm==32) Disp(2,0,14,"原谱：so  高音");
    				else if(mm==34) Disp(2,0,14,"原谱：la  高音");
    				else if(mm==36) Disp(2,0,14,"原谱：si  高音");
    				
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
    							Disp(3,5,4,"高音");
    							tune=1;
    							break;
    							case 42:
    							Disp(3,5,4,"低音");
    							tune=-1;
    							break;
                                default:
                                Disp(3,5,4,"中音");
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
    				    Disp(3,0,8,"在弹：do");
    					  nn=13+12*tune;flag=0;
    					 m=13+12*tune,n=8;
    				 }
    				 else if(OPT_CHECK&0x02)
    				 {
    				   Disp(3,0,8,"在弹：re");
    					 nn=15+12*tune;flag=0;
    					 m=15+12*tune,n=8;
    				 }
    				 else if(OPT_CHECK&0x04)
    				 {
    				   Disp(3,0,8,"在弹：mi");
    					 nn=17+12*tune;flag=0;
    					 m=17+12*tune,n=8;
    				 }
    				 else if(OPT_CHECK&0x08)
    				 {
    				   Disp(3,0,8,"在弹：fa");
    					 nn=18+12*tune;flag=0;
    					 m=18+12*tune,n=8;
    				 }
    				 else if(OPT_CHECK&0x10)
    				 {
    				  Disp(3,0,8,"在弹：so");
    					 nn=20+12*tune;flag=0;
    					 m=20+12*tune,n=8;
    				 }
    				 else if(OPT_CHECK&0x20)
    				 {
    				   Disp(3,0,8,"在弹：la");
    					 nn=22+12*tune;flag=0;
    					 m=22+12*tune,n=8;
    				 }
    				 else if(OPT_CHECK&0x40)
    				 {
    				   Disp(3,0,8,"在弹：si");
    					 nn=24+12*tune;flag=0;
    					 m=24+12*tune,n=8;
    				 }
    				 else{
    				   nn=0;m=0,n=2;
    				 	 Disp(3,0,8,"在弹：0");
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
    			if(check==1) Disp(4,0,8,"得分:1分");
					else if(check==2) Disp(4,0,8,"得分:2分");
    			else if(check==3) Disp(4,0,8,"得分:3分");
					else if(check==4) Disp(4,0,8,"得分:4分");
    			else if(check==5) Disp(4,0,8,"得分:5分");
					else if(check==6) Disp(4,0,8,"得分:6分");
					else if(check==7) Disp(4,0,8,"得分:7分");
					else if(check==8) Disp(4,0,8,"得分:8分");
					else if(check==9) Disp(4,0,8,"得分:9分");
    			else if(check>=10) Disp(4,0,10,"得分：10分");
					else Disp(4,0,8,"得分:0分");
    			check=0;
    			sum=0;
                //Disp(1,0,6,"1.返回");
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
				Disp(1,0,8,"记忆大师");
				Disp(2,0,8,"难度1-10");
				Disp(3,0,16,"难度高速度快分高");
				Disp(4,0,8,"15：退出");
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
									break; //跳出键盘的循环
							}
					}
				}//判断的循环
				
				if(key==43)
					break; //跳出case12的循环
				
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
				Ini_Lcd(); //刷新
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
					}//选择键盘的循环
					
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
					}//switch的循环
					if (i_cide<4&&key_cide<32)
						i_cide++;
					for (i=0;i<5;i++)
					{
						if (cide[i]-0x30)
            Disp(2,i,1,cide+i);
            else
            Disp(2,i,2," ");
					}//for循环
					for (i=0;i<5;i++)
					{
						Write_Cmd(0x88+i);
						Write_Data(0x00);
						Write_Data(0x00);
					}//for循环
					
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
								
						Disp(1,0,12,"很可惜失败了");
						Disp(4,0,8,"15：退出");
						while(1)
						{
							if ((KeyIO&0xf0)!=0xf0)
							{
								Delay_xMs(100);
								if ((KeyIO&0xf0)!=0xf0)
								{
									key=scankey();	
									if (key==43)
										break; //跳出键盘的循环
								}
							}	
						}//判断的循环
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
						Disp(1,0,12,"恭喜你成功了");
						if(time<=100)
							grade+=30;
						else if(time<=200)
							grade+=25;
						else
							grade+=20;
						temp[0] = grade/10+0x30;
						temp[1] = grade%10+0x30;
						temp[2] = '\0';
						Disp(2,0,6,"得分：");
						Disp(2,4,2,temp);
						Disp(4,0,8,"15：退出");
						while(1)
						{
							if ((KeyIO&0xf0)!=0xf0)
							{
								Delay_xMs(100);
								if ((KeyIO&0xf0)!=0xf0)
								{
									key=scankey();	
									if (key==43)
										break; //跳出键盘的循环
								}
							}	
						}//判断的循环
						if(key==43)
							break;
					}
					
				}//小循环
			}//case12的循环
			break;
		}//case12的大循环
            default: break;
            }   
        }		
      	break;	 
		default: break;
		}
	}   //switch(key_1)
    }   //while(1)
}   //void main

/*****************检测控制端口的状态*****************/
uchar ctrl_port_check(void)
{
		SW_CTRL = 0xFF;
		return 	SW_CTRL&0xF0;
}


	 
/****************延迟毫秒数************************/
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
    char xdata score[70][4]={0}; //score的第一个维度是tune，第二个维度是num，第三个维度是n，第四个维度是m
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
		if((P1&0xf0)!=0xf0) //如果有键按下
    	{
			Delay_xMs(100);   //延时去抖动
			if((KeyIO&0xf0)!=0xf0)   //再判断
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
		//显示乐谱
		
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
					Disp(4,0,8,"16：退出");
				}
			}	
	    	//排除开机显示乐谱
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

uchar scankey(void)//矩阵键盘翻转扫描
{
	uint keyvalue=0;
	uchar temp1,temp2,keycode;

	KeyIO=0xf0;		//行置0列置1
	temp1=KeyIO&0xf0;
	if((temp1&0xf0)==0xf0) return(0);  //若无键按下返回0
	KeyIO=0x0f;
	temp2=KeyIO&0x0f;					   //若有键按下，行置1列置0
	keycode=~(temp1|temp2);			   //获得键盘码
	switch(keycode)					   //根据键盘码返回键值
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