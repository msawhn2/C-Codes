void quadeqn(float a =-1.0, float b =9.0, float c =0)
{ 
const int n=10;
float det2;
float x1, x2;
float x[n], y[n];
det2  = b*b - 4*a*c;
if (det2>=0)
{
x1 = (-1.0*b - sqrt (det2))/ (2*a);
x2  = (-1.0*b + sqrt (det2))/ (2*a);
cout<<"the first root is "<<x1<<endl;
cout<<"the second root is "<<x2<<endl;

}
else
{
cout<<"determinant is negative"<<endl;
}
x[0]=x1;
x[n-1]=x2;
float dx = (x2-x1)/(n-1);
for (int i=0;i<n;i++)
{
x[i]=x1+i*dx;
y[i]=a*x[i]*x[i] + b*x[i] + c;
cout<<x[i]<<" "<<y[i]<<endl;
gr1 = new TGraph (n,x,y);
gr1->Draw("ALC*");

}
}
