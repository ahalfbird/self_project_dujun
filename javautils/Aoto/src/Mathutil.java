




import java.util.Random;
public class Mathutil {
	
//	public static void main(String[] args) {
//		
//		Random ran2 = new Random(1);
//		double x[]= {0,0,0,0,0};
//		int a,b,c,d,e,f,g;
//		for(int i=0;i<10;i++)
//		{
//			a=ran2.nextInt(10);
//			b=ran2.nextInt(10);
//			c=ran2.nextInt(10);
//			d=ran2.nextInt(10);
//			e=ran2.nextInt(10);
//			f=ran2.nextInt(10);
//			x=_X2Y2(a,b,c,d,e,f);
//			if(x[0]<0)
//				continue;
//			System.out.printf("[a1:   %-3d]   [b1:   %-3d]   [c1:   %-3d] [a2:   %-3d]   [b2:   %-3d]   [c2:   %-3d]\n",a,b,c,d,e,f);
//			System.out.printf("[x0:%3.3f]   [x1:%3.3f]   [x2:%3.3f]   [x1:%3.3f]   [x2:%3.3f]   \n",x[0],x[1],x[2],x[3],x[4]);
//		}
//		
////		x=_X2Y2(1,0,2,1,1,1);
////		System.out.printf("\n[x0:%3.3f]   [x1:%3.3f]   [x2:%3.3f]   [x1:%3.3f]   [x2:%3.3f]   \n",x[0],x[1],x[2],x[3],x[4]);
//		
//		
//
//		return;
//	}
	
	
	
	
	
//?????????????????	{a1*x1+b1*x2=c1,a2*x1+b2*x2=c2}   {det,x,y}
public static double[] _2X(double a1,double b1,double c1,double a2,double b2,double c2)
	{
	
	double X[]= {-1,0,0};
		
	double det=0;
	det=a1*b2-a2*b1;
	if(det==0)
	{
		System.out.println("?????????????????????");
		return X;
	}
	X[0]=1;
	X[1]=(b2*c1-b1*c2)/det;
	X[2]=(c2*a1-c1*a2)/det;
	
		return X;
		
	}
	
//?????????????????x??+bx+c=0}  {det,x1,x2}
public static double[] _X2(double a,double b,double c)
{
	double det;
	double x[]= {-1,0,0};
	
	double tmp;
	det=b*b-4*a*c;
	if(det<0)
	{
		System.out.println("????????????????????");
		return x;
	}
	x[0]=1;
	det=Math.sqrt(det);
	x[1]=(-b-det)/(2*a);
	x[2]=(-b+det)/(2*a);
	return x;
	
	}

//?????????????????????(x1-a1)2+(x2-b1)2=c1,(x1-a2)2+(x2-b2)=c2} {det,x1,x2,x1,x2}
public static double[] _X2Y2(double a1,double b1,double c1,double a2,double b2,double c2)
{
	double X[]= {-1,0,0,0,0};
	double tmpi;
	double tmpj;
	
	double det=0;
	det=(a1-a2)*(a1-a2)+(b1-b2)*(b1-b2);
	det=Math.sqrt(det);
	tmpi=Math.sqrt(c1);
	tmpj=Math.sqrt(c2);
	tmpi=tmpi+tmpj;
//	System.out.printf("\ndet:%-3.3f  r1%-3.3f  r2%-3.3f\n",det,tmpi,tmpj);
	if(det>tmpi)
		return X;
	
	double m,n,q;
	//mx1+nx2+q=0;
	m=2*(a2-a1);
	n=2*(b2-b1);
	q=(a1-a2)*(a1+a2)+(b1-b2)*(b1+b2)-c1+c2;
	
//	System.out.printf("\n%-3.3fx1+%-3.3fx2+%-3.3f=0\n",m,n,q);
	
	double tmpa,tmpb,tmpc,tmppa,tmppb,tmpppb;
	
	//x2=tmppa x1 + tmppb;
	tmppa=-m/n;
	tmppb=-q/n;
	tmpppb=tmppb-b1;
//	System.out.printf("\ntmpppb%-3.3f\n",tmpppb);
//	System.out.printf("\nx2=%-3.3fx1 + %-3.3f\n",tmppa,tmppb);
	
	tmpa=1+tmppa*tmppa;
	tmpb=-2*(a1-tmppa*tmpppb);
	tmpc=a1*a1+tmpppb*tmpppb-c1;
//	System.out.printf("\ntmpppb%-3.3f\n",tmpppb);
//	System.out.printf("\n%-3.3fx?? + %-3.3fx+%-3.3f=0\n",tmpa,tmpb,tmpc);
	
	double _x[]= {1,0,0};
	_x=_X2(tmpa,tmpb,tmpc);
	if(_x[0]<0)
	{
	  X[0]=-1;
	  return X;
	}
	
	X[1]=_x[1];
	X[2]=tmppa*X[1]+tmppb;
	
	X[3]=_x[2];
	X[4]=tmppa*X[3]+tmppb;
	
	X[0]=1;
	return X;
}



}
