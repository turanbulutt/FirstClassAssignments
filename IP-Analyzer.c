// Ahmet Turan Bulut 2315174
#include<stdio.h>
#include<math.h>

int main(){
	
int x=5,base,ip10,ip20,ip30,ip40,t=0,sub10,sub20,sub30,sub40,remain,bin10=0,bin20=0,bin30=0,bin40=0,count=1,dip10,dip20,dip30,dip40,sub_bin10=0,sub_bin20=0,sub_bin30=0,sub_bin40=0;
int sub_dip10,sub_dip20,sub_dip30,sub_dip40,IP10,IP20,IP30,IP40,IP50,IP60,IP70,IP80,SUBIP10,SUBIP20,SUBIP30,SUBIP40,SUBIP50,SUBIP60,SUBIP70,SUBIP80,fordigit10,fordigit20,fordigit30;
int fordigit40,digit10=0,zero10=0,digit20=0,zero20=0,digit30=0,zero30=0,digit40=0,zero40=0,zerototal=0,host=0;
char dot1,dot2,dot3,ip1,ip2,ip3,ip4,ip5,ip6,ip7,ip8,ip0,sub_dot1,sub_dot2,sub_dot3,sub0,sub1,sub2,sub3,sub4,sub5,sub6,sub7,sub8;

while(x!=6)
{
	switch(x)
	{
		case 1:
		{
			if(base==16)
			{
				switch(ip1)    //for translate hexadecimal to decimal 
				{
					case '1':IP10=1;break;
					case '2':IP10=2;break;
					case '3':IP10=3;break;
					case '4':IP10=4;break;
					case '5':IP10=5;break;
					case '6':IP10=6;break;
					case '7':IP10=7;break;
					case '8':IP10=8;break;
					case '9':IP10=9;break;
					case 'A':IP10=10;break;
					case 'B':IP10=11;break;
					case 'C':IP10=12;break;
					case 'D':IP10=13;break;
					case 'E':IP10=14;break;
					case 'F':IP10=15;break;
				}
				switch(ip2)
				{
					case '1':IP20=1;break;
					case '2':IP20=2;break;
					case '3':IP20=3;break;
					case '4':IP20=4;break;
					case '5':IP20=5;break;
					case '6':IP20=6;break;
					case '7':IP20=7;break;
					case '8':IP20=8;break;
					case '9':IP20=9;break;
					case 'A':IP20=10;break;
					case 'B':IP20=11;break;
					case 'C':IP20=12;break;
					case 'D':IP20=13;break;
					case 'E':IP20=14;break;
					case 'F':IP20=15;break;
				}
				ip10=IP10*16+IP20;
				switch(ip3)
				{
					case '1':IP30=1;break;
					case '2':IP30=2;break;
					case '3':IP30=3;break;
					case '4':IP30=4;break;
					case '5':IP30=5;break;
					case '6':IP30=6;break;
					case '7':IP30=7;break;
					case '8':IP30=8;break;
					case '9':IP30=9;break;
					case 'A':IP30=10;break;
					case 'B':IP30=11;break;
					case 'C':IP30=12;break;
					case 'D':IP30=13;break;
					case 'E':IP30=14;break;
					case 'F':IP30=15;break;
				}
				switch(ip4)
				{
					case '1':IP40=1;break;
					case '2':IP40=2;break;
					case '3':IP40=3;break;
					case '4':IP40=4;break;
					case '5':IP40=5;break;
					case '6':IP40=6;break;
					case '7':IP40=7;break;
					case '8':IP40=8;break;
					case '9':IP40=9;break;
					case 'A':IP40=10;break;
					case 'B':IP40=11;break;
					case 'C':IP40=12;break;
					case 'D':IP40=13;break;
					case 'E':IP40=14;break;
					case 'F':IP40=15;break;
				}
				ip20=IP30*16+IP40;
				switch(ip5)
				{
					case '1':IP50=1;break;
					case '2':IP50=2;break;
					case '3':IP50=3;break;
					case '4':IP50=4;break;
					case '5':IP50=5;break;
					case '6':IP50=6;break;
					case '7':IP50=7;break;
					case '8':IP50=8;break;
					case '9':IP50=9;break;
					case 'A':IP50=10;break;
					case 'B':IP50=11;break;
					case 'C':IP50=12;break;
					case 'D':IP50=13;break;
					case 'E':IP50=14;break;
					case 'F':IP50=15;break;
				}
				switch(ip6)
				{
					case '1':IP60=1;break;
					case '2':IP60=2;break;
					case '3':IP60=3;break;
					case '4':IP60=4;break;
					case '5':IP60=5;break;
					case '6':IP60=6;break;
					case '7':IP60=7;break;
					case '8':IP60=8;break;
					case '9':IP60=9;break;
					case 'A':IP60=10;break;
					case 'B':IP60=11;break;
					case 'C':IP60=12;break;
					case 'D':IP60=13;break;
					case 'E':IP60=14;break;
					case 'F':IP60=15;break;
				}
				ip30=IP50*16+IP60;
				switch(ip7)
				{
					case '1':IP70=1;break;
					case '2':IP70=2;break;
					case '3':IP70=3;break;
					case '4':IP70=4;break;
					case '5':IP70=5;break;
					case '6':IP70=6;break;
					case '7':IP70=7;break;
					case '8':IP70=8;break;
					case '9':IP70=9;break;
					case 'A':IP70=10;break;
					case 'B':IP70=11;break;
					case 'C':IP70=12;break;
					case 'D':IP70=13;break;
					case 'E':IP70=14;break;
					case 'F':IP70=15;break;
				}
				switch(ip8)
				{
					case '1':IP80=1;break;
					case '2':IP80=2;break;
					case '3':IP80=3;break;
					case '4':IP80=4;break;
					case '5':IP80=5;break;
					case '6':IP80=6;break;
					case '7':IP80=7;break;
					case '8':IP80=8;break;
					case '9':IP80=9;break;
					case 'A':IP80=10;break;
					case 'B':IP80=11;break;
					case 'C':IP80=12;break;
					case 'D':IP80=13;break;
					case 'E':IP80=14;break;
					case 'F':IP80=15;break;
				}
				ip40=IP70*16+IP80;
			}
			//for translate decimal to binary
			dip10=ip10;
			dip20=ip20;
			dip30=ip30;
			dip40=ip40;
			while(dip10!=0)
			{
				remain=dip10%2;
				bin10=bin10+(remain*count);
				dip10=dip10/2;
				count=count*10;
			}
			count=1;
			while(dip20!=0)
			{
				remain=dip20%2;
				bin20=bin20+(remain*count);
				dip20=dip20/2;
				count=count*10;
			}
			count=1;
			while(dip30!=0)
			{
				remain=dip30%2;
				bin30=bin30+(remain*count);
				dip30=dip30/2;
				count=count*10;
			}
			count=1;
			while(dip40!=0)
			{
				remain=dip40%2;
				bin40=bin40+(remain*count);
				dip40=dip40/2;
				count=count*10;
			}
			count=1;
			printf("\n%08d.%08d.%08d.%08d \n \n",bin10,bin20,bin30,bin40);
			bin10=0; //for doing calculations true after that
			bin20=0;
			bin30=0;
			bin40=0;
			printf("1.Convert IP address to binary \n2.Convert subnet mask to binary \n");
			printf("3.Specify the class of the IP address \n4.Specify the number of host addresses available \n");
			printf("5.Provide new IP Address and subnet mask \n6.Exit\n");
			printf("\nPlease choose an option:");
			scanf("%d",&x);
			break;
		}
		case 2:
		{
			if(base==16)
			{
				switch(sub1) //for translate hexadecimal to decimal
				{
					case '1':SUBIP10=1;break;
					case '2':SUBIP10=2;break;
					case '3':SUBIP10=3;break;
					case '4':SUBIP10=4;break;
					case '5':SUBIP10=5;break;
					case '6':SUBIP10=6;break;
					case '7':SUBIP10=7;break;
					case '8':SUBIP10=8;break;
					case '9':SUBIP10=9;break;
					case 'A':SUBIP10=10;break;
					case 'B':SUBIP10=11;break;
					case 'C':SUBIP10=12;break;
					case 'D':SUBIP10=13;break;
					case 'E':SUBIP10=14;break;
					case 'F':SUBIP10=15;break;
				}
				switch(sub2)
				{
					case '1':SUBIP20=1;break;
					case '2':SUBIP20=2;break;
					case '3':SUBIP20=3;break;
					case '4':SUBIP20=4;break;
					case '5':SUBIP20=5;break;
					case '6':SUBIP20=6;break;
					case '7':SUBIP20=7;break;
					case '8':SUBIP20=8;break;
					case '9':SUBIP20=9;break;
					case 'A':SUBIP20=10;break;
					case 'B':SUBIP20=11;break;
					case 'C':SUBIP20=12;break;
					case 'D':SUBIP20=13;break;
					case 'E':SUBIP20=14;break;
					case 'F':SUBIP20=15;break;
				}
				sub10=SUBIP10*16+SUBIP20;
				switch(sub3)
				{
					case '1':SUBIP30=1;break;
					case '2':SUBIP30=2;break;
					case '3':SUBIP30=3;break;
					case '4':SUBIP30=4;break;
					case '5':SUBIP30=5;break;
					case '6':SUBIP30=6;break;
					case '7':SUBIP30=7;break;
					case '8':SUBIP30=8;break;
					case '9':SUBIP30=9;break;
					case 'A':SUBIP30=10;break;
					case 'B':SUBIP30=11;break;
					case 'C':SUBIP30=12;break;
					case 'D':SUBIP30=13;break;
					case 'E':SUBIP30=14;break;
					case 'F':SUBIP30=15;break;
				}
				switch(sub4)
				{
					case '1':SUBIP40=1;break;
					case '2':SUBIP40=2;break;
					case '3':SUBIP40=3;break;
					case '4':SUBIP40=4;break;
					case '5':SUBIP40=5;break;
					case '6':SUBIP40=6;break;
					case '7':SUBIP40=7;break;
					case '8':SUBIP40=8;break;
					case '9':SUBIP40=9;break;
					case 'A':SUBIP40=10;break;
					case 'B':SUBIP40=11;break;
					case 'C':SUBIP40=12;break;
					case 'D':SUBIP40=13;break;
					case 'E':SUBIP40=14;break;
					case 'F':SUBIP40=15;break;
				}
				sub20=SUBIP30*16+SUBIP40;
				switch(sub5)
				{
					case '1':SUBIP50=1;break;
					case '2':SUBIP50=2;break;
					case '3':SUBIP50=3;break;
					case '4':SUBIP50=4;break;
					case '5':SUBIP50=5;break;
					case '6':SUBIP50=6;break;
					case '7':SUBIP50=7;break;
					case '8':SUBIP50=8;break;
					case '9':SUBIP50=9;break;
					case 'A':SUBIP50=10;break;
					case 'B':SUBIP50=11;break;
					case 'C':SUBIP50=12;break;
					case 'D':SUBIP50=13;break;
					case 'E':SUBIP50=14;break;
					case 'F':SUBIP50=15;break;
				}
				switch(sub6)
				{
					case '1':SUBIP60=1;break;
					case '2':SUBIP60=2;break;
					case '3':SUBIP60=3;break;
					case '4':SUBIP60=4;break;
					case '5':SUBIP60=5;break;
					case '6':SUBIP60=6;break;
					case '7':SUBIP60=7;break;
					case '8':SUBIP60=8;break;
					case '9':SUBIP60=9;break;
					case 'A':SUBIP60=10;break;
					case 'B':SUBIP60=11;break;
					case 'C':SUBIP60=12;break;
					case 'D':SUBIP60=13;break;
					case 'E':SUBIP60=14;break;
					case 'F':SUBIP60=15;break;
				}
				sub30=SUBIP50*16+SUBIP60;
				switch(sub7)
				{
					case '1':SUBIP70=1;break;
					case '2':SUBIP70=2;break;
					case '3':SUBIP70=3;break;
					case '4':SUBIP70=4;break;
					case '5':SUBIP70=5;break;
					case '6':SUBIP70=6;break;
					case '7':SUBIP70=7;break;
					case '8':SUBIP70=8;break;
					case '9':SUBIP70=9;break;
					case 'A':SUBIP70=10;break;
					case 'B':SUBIP70=11;break;
					case 'C':SUBIP70=12;break;
					case 'D':SUBIP70=13;break;
					case 'E':SUBIP70=14;break;
					case 'F':SUBIP70=15;break;
				}
				switch(sub8)
				{
					case '1':SUBIP80=1;break;
					case '2':SUBIP80=2;break;
					case '3':SUBIP80=3;break;
					case '4':SUBIP80=4;break;
					case '5':SUBIP80=5;break;
					case '6':SUBIP80=6;break;
					case '7':SUBIP80=7;break;
					case '8':SUBIP80=8;break;
					case '9':SUBIP80=9;break;
					case 'A':SUBIP80=10;break;
					case 'B':SUBIP80=11;break;
					case 'C':SUBIP80=12;break;
					case 'D':SUBIP80=13;break;
					case 'E':SUBIP80=14;break;
					case 'F':SUBIP80=15;break;
				}
				sub40=SUBIP70*16+SUBIP80;
			}
			//for translate decimal to binary
			sub_dip10=sub10;
			sub_dip20=sub20;
			sub_dip30=sub30;
			sub_dip40=sub40;
			while(sub_dip10!=0)
			{
				remain=sub_dip10%2;
				sub_bin10=sub_bin10+(remain*count);
				sub_dip10=sub_dip10/2;
				count=count*10;
			}
			count=1;
			while(sub_dip20!=0)
			{
				remain=sub_dip20%2;
				sub_bin20=sub_bin20+(remain*count);
				sub_dip20=sub_dip20/2;
				count=count*10;
			}
			count=1;
			while(sub_dip30!=0)
			{
				remain=sub_dip30%2;
				sub_bin30=sub_bin30+(remain*count);
				sub_dip30=sub_dip30/2;
				count=count*10;
			}
			count=1;
			while(sub_dip40!=0)
			{
				remain=sub_dip40%2;
				sub_bin40=sub_bin40+(remain*count);
				sub_dip40=sub_dip40/2;
				count=count*10;
			}
			count=1;
			printf("\n%08d.%08d.%08d.%08d \n \n",sub_bin10,sub_bin20,sub_bin30,sub_bin40);
			sub_bin10=0;//for doing calculations true after that
			sub_bin20=0;
			sub_bin30=0;
			sub_bin40=0;			
			printf("1.Convert IP address to binary \n2.Convert subnet mask to binary \n");
			printf("3.Specify the class of the IP address \n4.Specify the number of host addresses available \n");
			printf("5.Provide new IP Address and subnet mask \n6.Exit\n");
			printf("\nPlease choose an option:");
			scanf("%d",&x);
			break;
		}
		case 3:
		{
			if(base==16) //for translate hexadecimal to decimal
			{
				switch(ip1)
				{
					case '1':IP10=1;break;
					case '2':IP10=2;break;
					case '3':IP10=3;break;
					case '4':IP10=4;break;
					case '5':IP10=5;break;
					case '6':IP10=6;break;
					case '7':IP10=7;break;
					case '8':IP10=8;break;
					case '9':IP10=9;break;
					case 'A':IP10=10;break;
					case 'B':IP10=11;break;
					case 'C':IP10=12;break;
					case 'D':IP10=13;break;
					case 'E':IP10=14;break;
					case 'F':IP10=15;break;
				}
				switch(ip2)
				{
					case '1':IP20=1;break;
					case '2':IP20=2;break;
					case '3':IP20=3;break;
					case '4':IP20=4;break;
					case '5':IP20=5;break;
					case '6':IP20=6;break;
					case '7':IP20=7;break;
					case '8':IP20=8;break;
					case '9':IP20=9;break;
					case 'A':IP20=10;break;
					case 'B':IP20=11;break;
					case 'C':IP20=12;break;
					case 'D':IP20=13;break;
					case 'E':IP20=14;break;
					case 'F':IP20=15;break;
				}
				ip10=IP10*16+IP20;	
			}
			//I translate binary numbers to decimal so that don't need to go binary numbers
			if(ip10>=0 && ip10<=127)
			{
				printf("\nThe class of given IP Address is: A \n \n");
			}
			else if(ip10>=128 && ip10<=191)
			{
				printf("\nThe class of given IP Address is: B \n \n");
			}
			else if(ip10>=192 && ip10<=223)
			{
				printf("\nThe class of given IP Address is: C \n \n");
			}
			else
			{
				printf("\nThe class of given IP Address is: D \n \n");
			}
			
			printf("1.Convert IP address to binary \n2.Convert subnet mask to binary \n");
			printf("3.Specify the class of the IP address \n4.Specify the number of host addresses available \n");
			printf("5.Provide new IP Address and subnet mask \n6.Exit\n");
			printf("\nPlease choose an option:");
			scanf("%d",&x);
			break;
		}
		case 4:
		{
			if(base==16)
			{
				switch(sub1) //for translate hexadecimal to decimal
				{
					case '1':SUBIP10=1;break;
					case '2':SUBIP10=2;break;
					case '3':SUBIP10=3;break;
					case '4':SUBIP10=4;break;
					case '5':SUBIP10=5;break;
					case '6':SUBIP10=6;break;
					case '7':SUBIP10=7;break;
					case '8':SUBIP10=8;break;
					case '9':SUBIP10=9;break;
					case 'A':SUBIP10=10;break;
					case 'B':SUBIP10=11;break;
					case 'C':SUBIP10=12;break;
					case 'D':SUBIP10=13;break;
					case 'E':SUBIP10=14;break;
					case 'F':SUBIP10=15;break;
				}
				switch(sub2)
				{
					case '1':SUBIP20=1;break;
					case '2':SUBIP20=2;break;
					case '3':SUBIP20=3;break;
					case '4':SUBIP20=4;break;
					case '5':SUBIP20=5;break;
					case '6':SUBIP20=6;break;
					case '7':SUBIP20=7;break;
					case '8':SUBIP20=8;break;
					case '9':SUBIP20=9;break;
					case 'A':SUBIP20=10;break;
					case 'B':SUBIP20=11;break;
					case 'C':SUBIP20=12;break;
					case 'D':SUBIP20=13;break;
					case 'E':SUBIP20=14;break;
					case 'F':SUBIP20=15;break;
				}
				sub10=SUBIP10*16+SUBIP20;
				switch(sub3)
				{
					case '1':SUBIP30=1;break;
					case '2':SUBIP30=2;break;
					case '3':SUBIP30=3;break;
					case '4':SUBIP30=4;break;
					case '5':SUBIP30=5;break;
					case '6':SUBIP30=6;break;
					case '7':SUBIP30=7;break;
					case '8':SUBIP30=8;break;
					case '9':SUBIP30=9;break;
					case 'A':SUBIP30=10;break;
					case 'B':SUBIP30=11;break;
					case 'C':SUBIP30=12;break;
					case 'D':SUBIP30=13;break;
					case 'E':SUBIP30=14;break;
					case 'F':SUBIP30=15;break;
				}
				switch(sub4)
				{
					case '1':SUBIP40=1;break;
					case '2':SUBIP40=2;break;
					case '3':SUBIP40=3;break;
					case '4':SUBIP40=4;break;
					case '5':SUBIP40=5;break;
					case '6':SUBIP40=6;break;
					case '7':SUBIP40=7;break;
					case '8':SUBIP40=8;break;
					case '9':SUBIP40=9;break;
					case 'A':SUBIP40=10;break;
					case 'B':SUBIP40=11;break;
					case 'C':SUBIP40=12;break;
					case 'D':SUBIP40=13;break;
					case 'E':SUBIP40=14;break;
					case 'F':SUBIP40=15;break;
				}
				sub20=SUBIP30*16+SUBIP40;
				switch(sub5)
				{
					case '1':SUBIP50=1;break;
					case '2':SUBIP50=2;break;
					case '3':SUBIP50=3;break;
					case '4':SUBIP50=4;break;
					case '5':SUBIP50=5;break;
					case '6':SUBIP50=6;break;
					case '7':SUBIP50=7;break;
					case '8':SUBIP50=8;break;
					case '9':SUBIP50=9;break;
					case 'A':SUBIP50=10;break;
					case 'B':SUBIP50=11;break;
					case 'C':SUBIP50=12;break;
					case 'D':SUBIP50=13;break;
					case 'E':SUBIP50=14;break;
					case 'F':SUBIP50=15;break;
				}
				switch(sub6)
				{
					case '1':SUBIP60=1;break;
					case '2':SUBIP60=2;break;
					case '3':SUBIP60=3;break;
					case '4':SUBIP60=4;break;
					case '5':SUBIP60=5;break;
					case '6':SUBIP60=6;break;
					case '7':SUBIP60=7;break;
					case '8':SUBIP60=8;break;
					case '9':SUBIP60=9;break;
					case 'A':SUBIP60=10;break;
					case 'B':SUBIP60=11;break;
					case 'C':SUBIP60=12;break;
					case 'D':SUBIP60=13;break;
					case 'E':SUBIP60=14;break;
					case 'F':SUBIP60=15;break;
				}
				sub30=SUBIP50*16+SUBIP60;
				switch(sub7)
				{
					case '1':SUBIP70=1;break;
					case '2':SUBIP70=2;break;
					case '3':SUBIP70=3;break;
					case '4':SUBIP70=4;break;
					case '5':SUBIP70=5;break;
					case '6':SUBIP70=6;break;
					case '7':SUBIP70=7;break;
					case '8':SUBIP70=8;break;
					case '9':SUBIP70=9;break;
					case 'A':SUBIP70=10;break;
					case 'B':SUBIP70=11;break;
					case 'C':SUBIP70=12;break;
					case 'D':SUBIP70=13;break;
					case 'E':SUBIP70=14;break;
					case 'F':SUBIP70=15;break;
				}
				switch(sub8)
				{
					case '1':SUBIP80=1;break;
					case '2':SUBIP80=2;break;
					case '3':SUBIP80=3;break;
					case '4':SUBIP80=4;break;
					case '5':SUBIP80=5;break;
					case '6':SUBIP80=6;break;
					case '7':SUBIP80=7;break;
					case '8':SUBIP80=8;break;
					case '9':SUBIP80=9;break;
					case 'A':SUBIP80=10;break;
					case 'B':SUBIP80=11;break;
					case 'C':SUBIP80=12;break;
					case 'D':SUBIP80=13;break;
					case 'E':SUBIP80=14;break;
					case 'F':SUBIP80=15;break;
				}
				sub40=SUBIP70*16+SUBIP80;
			}
			sub_dip10=sub10;
			sub_dip20=sub20;
			sub_dip30=sub30;
			sub_dip40=sub40;
			while(sub_dip10!=0) //for translate decimal to binary
			{
				remain=sub_dip10%2;
				sub_bin10=sub_bin10+(remain*count);
				sub_dip10=sub_dip10/2;
				count=count*10;
			}
			count=1;
			while(sub_dip20!=0)
			{
				remain=sub_dip20%2;
				sub_bin20=sub_bin20+(remain*count);
				sub_dip20=sub_dip20/2;
				count=count*10;
			}
			count=1;
			while(sub_dip30!=0)
			{
				remain=sub_dip30%2;
				sub_bin30=sub_bin30+(remain*count);
				sub_dip30=sub_dip30/2;
				count=count*10;
			}
			count=1;
			while(sub_dip40!=0)
			{
				remain=sub_dip40%2;
				sub_bin40=sub_bin40+(remain*count);
				sub_dip40=sub_dip40/2;
				count=count*10;
			}
			//sub_bin10-20-30-40
			fordigit10=sub_bin10;
			fordigit20=sub_bin20;
			fordigit30=sub_bin30;
			fordigit40=sub_bin40;
			while(fordigit10!=0) // for found the number has how many digits
			{
				fordigit10=fordigit10/10;
				digit10++;
			}
			digit10=8-digit10; //I remove number of digit to 8 for found how many zero it have at beginning
			while(sub_bin10!=0)//for found how many zero it have in the number
			{
				remain=sub_bin10%2;
				if(remain==0){
					zero10++;
				}
				sub_bin10=sub_bin10/10;
			} 
			zero10=zero10+digit10; // total 0 of 8bit number
			while(fordigit20!=0)
			{
				fordigit20=fordigit20/10;
				digit20++;
			}
			digit20=8-digit20;
			while(sub_bin20!=0)
			{
				remain=sub_bin20%2;
				if(remain==0){
					zero20++;
				}
				sub_bin20=sub_bin20/10;
			} 
			zero20=zero20+digit20;
			while(fordigit30!=0)
			{
				fordigit30=fordigit30/10;
				digit30++;
			}
			digit30=8-digit30;
			while(sub_bin30!=0)
			{
				remain=sub_bin30%2;
				if(remain==0){
					zero30++;
				}
				sub_bin30=sub_bin30/10;
			} 
			zero30=zero30+digit30;
			while(fordigit40!=0)
			{
				fordigit40=fordigit40/10;
				digit40++;
			}
			digit40=8-digit40;
			while(sub_bin40!=0)
			{
				remain=sub_bin40%2;
				if(remain==0){
					zero40++;
				}
				sub_bin40=sub_bin40/10;
			}
			zero40=zero40+digit40; //total 0 in subnet mask
			zerototal=zero10+zero20+zero30+zero40;
			host=pow(2,zerototal)-2;
			printf("\nThe number of available host addresses for the given Subnet Mask: %d \n \n",host); 
			zero10=0;
			zero20=0;
			zero30=0;
			zero40=0;
			digit10=0;
			digit20=0;
			digit30=0;
			digit40=0;
			printf("1.Convert IP address to binary \n2.Convert subnet mask to binary \n");
			printf("3.Specify the class of the IP address \n4.Specify the number of host addresses available \n");
			printf("5.Provide new IP Address and subnet mask \n6.Exit\n");
			printf("\nPlease choose an option:");
			scanf("%d",&x);
			break;
		}
		case 5:
		{
			printf("Please enter the Base for your IP Address (10/16):");
			scanf("%d",&base);
			while (base!=16)
			{
				if(base!=10)
				{
					printf("\nSorry that is not a valid base! \n\n");
					printf("Please enter the Base for your IP Address (10/16):");
					scanf("%d",&base);
				}
				else
				{
					break;
				}
	
			}
			if(base==10)
			{
				while(t==0)
				{
					printf("Please enter the IP Address:");
					scanf("%d",&ip10);
					scanf("%c",&dot1);
					scanf("%d",&ip20);
					scanf("%c",&dot2);
					scanf("%d",&ip30);
					scanf("%c",&dot3);
					scanf("%d",&ip40);
					if(ip10>=0 && ip10<256 && ip20>=0 && ip20<256 && ip30>=0 && ip30<256 & ip40>=0 && ip40<256 && dot1==46 && dot2==46 && dot3==46)
					{
						printf("\nThanks it is a valid IP Address \n \n");
						break;
					}
					printf("\nThis is NOT a valid IP Address! \n\n");
				}
			}
			if(base==16)
			{
				while (t==0)
				{
					printf("Please enter the IP Address:");
					scanf("%c",&ip0);  //for get rid of the enter because when we taking base from user click enter and here ip=enter
					scanf("%c",&ip1);
					scanf("%c",&ip2);
					scanf("%c",&dot1);
					scanf("%c",&ip3);
					scanf("%c",&ip4);
					scanf("%c",&dot2);
					scanf("%c",&ip5);
					scanf("%c",&ip6);
					scanf("%c",&dot3);
					scanf("%c",&ip7);
					scanf("%c",&ip8);;
					if(((ip1>=48 && ip1<=58)|| (ip1>=65 && ip1<=70)) &&((ip2>=48 && ip2<=58)||(ip2>=65 && ip2<=70))&&( (ip3>=48 && ip3<=58)||(ip3>=65 &&ip3<=70))&&((ip4>=48 && ip4<=58)||(ip4>=65 && ip4<=70))&&((ip5>=48 && ip5<=58)||(ip5>=65 && ip5<=70))&&((ip6>=48 && ip6<=58)||(ip6>=65 && ip6<=70))&&((ip7>=48 && ip7<=58)||(ip7>=65 && ip7<=70))&&((ip8>=48 && ip8<=58)||(ip8>=65 && ip8<=70))&& dot1==46 && dot2==46 && dot3==46)
					{
						printf("\nThanks it is a valid IP Address \n \n");
						break;
					}
					printf("\nThis is NOT a valid IP Address! \n\n");
				}
			}
			if(base==10)
			{
				while(t==0)
				{
					printf("Please enter the Subnet Mask:");
					scanf("%d",&sub10);
					scanf("%c",&sub_dot1);
					scanf("%d",&sub20);
					scanf("%c",&sub_dot2);
					scanf("%d",&sub30);
					scanf("%c",&sub_dot3);
					scanf("%d",&sub40);
					if(sub10>=0 && sub10<256 && sub20>=0 && sub20<256 && sub30>=0 && sub30<256 & sub40>=0 && sub40<256 && sub_dot1==46 && sub_dot2==46 && sub_dot3==46)
					{
						printf("\nThanks it is a valid Subnet Mask \n \n");
						break;
					}
					printf("\nThis is NOT a valid Subnet Mask! \n\n");
				}
			}
			if(base==16)
			{
				while (t==0)
				{
					printf("Please enter the Subnet Mask:");
					scanf("%c",&sub0);  //for get rid of the enter because when we taking subnet masks from user click enter and here ip=enter
					scanf("%c",&sub1);
					scanf("%c",&sub2);
					scanf("%c",&sub_dot1);
					scanf("%c",&sub3);
					scanf("%c",&sub4);
					scanf("%c",&sub_dot2);
					scanf("%c",&sub5);
					scanf("%c",&sub6);
					scanf("%c",&sub_dot3);
					scanf("%c",&sub7);
					scanf("%c",&sub8);
					if(((sub1>=48 && sub1<=58)|| (sub1>=65 && sub1<=70)) &&((sub2>=48 && sub2<=58)||(sub2>=65 && sub2<=70))&&( (sub3>=48 && sub3<=58)||(sub3>=65 &&sub3<=70))&&((sub4>=48 && sub4<=58)||(sub4>=65 && sub4<=70))&&((sub5>=48 && sub5<=58)||(sub5>=65 && sub5<=70))&&((sub6>=48 && sub6<=58)||(sub6>=65 && sub6<=70))&&((sub7>=48 && sub7<=58)||(sub7>=65 && sub7<=70))&&((sub8>=48 && sub8<=58)||(sub8>=65 && sub8<=70))&& sub_dot1==46 && sub_dot2==46 && sub_dot3==46)
					{
						printf("\nThanks it is a valid Subnet Mask \n \n");
						break;
					}
					printf("\nThis is NOT a valid Subnet Mask! \n\n");
				}
			}	
			
			
			printf("1.Convert IP address to binary \n2.Convert subnet mask to binary \n");
			printf("3.Specify the class of the IP address \n4.Specify the number of host addresses available \n");
			printf("5.Provide new IP Address and subnet mask \n6.Exit\n");
			printf("\nPlease choose an option:");
			scanf("%d",&x);
			break;
		}
		default:
		{
			printf("You enter the wrong number please try again:");
			scanf("%d",&x);
			break;
		}	
	}
	
}


	
return 0;
}
