package com.Java_quwei_biancheng_100_li;

public class Demo2_7 
{
	/*
	 * @param args
	 */
	public static void main(String[] args)
	{
		int weight1,weight2,weight3,weight4,d1,d2,d3,d4,x,flag;
		int w1=0,w2=0,w3=0,w4=0;
		System.out.println("The weight is broke up as following 4 pieces:");
		for(weight1=1;weight1<=40;weight1++)
			for(weight2=weight1+1;weight2<=40-weight1;weight2++)
				for(weight3=weight2+1;weight3<=40-weight1-weight2;weight3++)
					if((weight4=40-weight1-weight2-weight3)>=weight3)
					{
						for(flag=1,x=1;x<41&&flag==1;x++)
							for(flag=0,d1=1;d1>-2;d1--)
								for(d2=1;d2>-2&&flag==0;d2--)
									for(d3=1;d3>-2&&flag==0;d2--)
										for(d4=1;d4>-2&&flag==0;d4--)
											if(x==weight1*d1+weight2*d2+weight3*d3+weight4*d4)
												flag=1;
						if(flag==1)
						{
							System.out.printf("%d %d %d %d\n", weight1,weight2,weight3,weight4);
							w1=weight1;
							w2=weight2;
							w3=weight3;
							w4=weight4;
						}
					}
		System.out.printf("\n%d %d %d %d\n", w1,w2,w3,w4);
		String left= "",right="";
		for(int i=1;i<=40;i++)
			for(int a1=-1;a1<=1;a1++)
				for(int a2=-1;a2<=1;a2++)
					for(int a3=-1;a3<=1;a3++)
						for(int a4=-1;a4<=1;a4++)
						{
							if(i==a1*w4+a2*w3+a3*w2+a4*w1)
							{
								boolean f=true;
								left=i+"";
								switch(a1) 
								{
								case -1:
									left=left+"+"+w4;
									break;
								case 1:
									if(f)
										right=right+w4;
									else
										right=right+"+"+w4;
									f=false;
									break;
								}
								switch(a2)
								{
								case -1:
									left=left+"+"+w3;
									break;
								case 1:
									right = right+"+"+w3;
									if(f)
										right=right+w3;
									else
										right=right+"+"+w3;
									f=false;
									break;
								}
								switch(a3)
								{
								case -1:
									left=left+"+"+w2;
									break;
								case 1:
									right = right+"+"+w2;
									if(f)
										right=right+w2;
									else
										right=right+"+"+w2;
									f=false;
									break;
								}
								switch(a4)
								{
								case -1:
									left=left+"+"+w1;
									break;
								case 1:
									right = right+"+"+w1;
									if(f)
										right=right+w1;
									else
										right=right+"+"+w1;
									f=false;
									break;
								}
								System.out.println(left+"="+right);
							}
							left="";
							right="";
						}
	}
}
