import java.util.*;
class subnet
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        String ip,first,mask=" ",subnetAdd="";
        char clas=' ',ch;
	int i,k=0,ct=0,ind;
        System.out.println("Enter ip address ");
        ip=sc.nextLine();
        ind=ip.indexOf('.');
	String ipArr[]=ip.split("\\.");
        if(ipArr.length==4)
        {
            first=ip.substring(0,ind);
            int f=Integer.parseInt(first);
            if(f>=0 && f<=127)
            {
                clas='A';
                mask="255.0.0.0";
            }
            else if(f>=128 && f<=191)
            {
                clas='B';
                mask="255.255.0.0";
            }
            else if(f>=192 && f<=223)
            {
                clas='C';
                mask="255.255.255.0";
            }
            else if(f>=224 && f<=239)
            clas='D';
            else if(f>=240 && f<=255)
            clas='E';
            else
            System.out.println("Invalid IP Address");
            if(clas=='A' || clas=='B' || clas=='C')
            {
                System.out.println("Subnet class "+clas);
                System.out.println("Subnet Mask "+mask);
            }
            else if(clas=='D')
            {
                System.out.println("Subnet class "+clas);
                System.out.println("Reserved for multicast");
            }
            else if(clas=='E')
            {
                System.out.println("Subnet class "+clas);
                System.out.println("Experimental");
            }
            if(mask!=" ")
            {
                String maskArr[]=mask.split("\\.");
                for(i=0;i<4;i++)
                {
                    int x=Integer.parseInt(ipArr[i]);  
                    int y=Integer.parseInt(maskArr[i]); 
                    int z=x&y;
                    subnetAdd+=z+".";
                }
                System.out.println("Subnet address is "+subnetAdd);
            }
        }
        else
        System.out.println("Invalid IP Address");
    }
}
