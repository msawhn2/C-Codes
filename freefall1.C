void freefall1(float h=100,float v_y0=0)
{
float g =9.8;       							//g is negative
float t_low = 0;
float yt_low;
float t_high = (h+v_y0)/g; 
float det;
float y,t; 
float e = 0.05*h; 
int N=100; 
float a = -0.5*g;
float b= v_y0;
float c= h;
const int n=10;
float det2;
float x1, x2;
float x[n], yy[n];


//numerical solution
det2  = b*b - 4*a*c;
if (det2>=0)
{
x1 = (-1.0*b - sqrt (det2))/ (2*a);

cout<<"the numerical solution is "<<x1<<endl;

}
else
{
cout<<"determinant is negative"<<endl;
}



float dx = ((h+v_y0)/g)/(n-1);
for (int i=0;i<=n;i++)
{
x[i]=i*dx;
yy[i]=a*x[i]*x[i] + b*x[i] + c;
}



gr1 = new TGraph (n,x,yy);
gr1->SetTitle("Time of flight");
gr1->GetXaxis()->SetTitle("time, [s]");
gr1->GetYaxis()->SetTitle("Height, [m]");
//gr1->SetMarkerStyle(21);
//gr1->Draw("ALC*");

d= new TCanvas("d","Time of flight",10,10,500,400);  
d->Draw();
gr1->SetMarkerStyle(21);
gr1->Draw("AP");


//exact solution
TF1*EOM = new TF1("EOM","[0]*x*x+[1]*x+[2]",t_low,t_high);
EOM->SetParameters(-1.0*g/2.0,v_y0,h);
EOM->SetLineColor(2);
EOM->Draw("same");

leg = new TLegend(0.13,0.4,0.35,0.25);
leg->AddEntry("EOM","Exact Solution","l");
leg->AddEntry("gr1","Numerical solution","p");
leg->Draw("same");



for(int j=0; j<N; j++){

t = 0.5*(t_low+t_high); 

y=EOM->Eval(t);

yt_low = EOM->Eval(t_low);

TLine *L = new TLine(t_low,yt_low,t_low,0);

L->Draw("same");

yt_high = EOM->Eval(t_high);

TLine*L1 = new TLine(t_high,0,t_high,yt_high);

L1->Draw("same");

if(fabs(y)<e)

        {break;}

if(y*yt_low>0)

        {t_low=t;}

else

      {t_high=t;}

              
              //cout<<y<<endl;


}

      TLine *L1 = new TLine(0,0,11.25,0);

       L1->Draw("same");


cout<<"the exact solution is "<<t <<endl;



}