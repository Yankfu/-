package Yankfu;
import java.util.*;                      
public class Pintia_cn_4_5 
{
    public static void main(String[] args) 
    {
    	Scanner in=new Scanner(System.in);
        String str=in.next();
        char[] ch=str.toCharArray();
        maopao(ch);
        String result = String.valueOf(ch);
        System.out.println(result);
        
    }
    
    public static void maopao(char[] ch)
    {
        for(int i =0;i<ch.length-1;i++)
        {
            for(int j=0;j<ch.length-1-i;j++) 
            {
                if(ch[j]>ch[j+1])
                {
                    char temp = ch[j];
                    ch[j]=ch[j+1];
                    ch[j+1]=temp;
                }
            }
        }
    }

}