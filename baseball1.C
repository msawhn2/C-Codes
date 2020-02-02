void baseball1(float dt=0.01, float v0=49.1744)
{
	
const int n=1000;
   float pi = 3.14159261;
    float Vx[n],Vy[n],x[n],y[n],t[n],V[n];
    float Fdragx[n], Fdragy[n]; 
    const int N=30;
    float range[N];
    float g =9.81;
    x[0]=0;
    y[0]=0;
    t[0]=0;
     float alpha[N];
    float alpha0 = 40;
    float vd=35;
    float dx=5;
    int count =0;
    float V[0] = v0;
    float Vwind = 4.4704;
    float d[n];
    float y0=10000;
    float alphaStep = 1;//(pi/180);

    for (int j=0;j<N;j++){


    alpha[j] = alpha0 + alphaStep*j;
    Vx[0] = v0*sin((alpha[j]*pi)/180);
    Vy[0] = v0*cos((alpha[j]*pi)/180);
 //cout<<Vx[0]<<" "<<Vy[0]<<endl;
      

      count = 0;
    for(int i=0;i<n-1;i++){
    	count++;

    V[i] = sqrt ((pow(Vx[i]-Vwind),2)+pow(Vy[i],2));
    //cout<<V[i]<<endl;
    d[i]= 0.0039 + (0.0058/(1+exp((V[i]-vd)/dx)));

    
    x[i+1]=x[i]+(Vx[i]*dt);

	y[i+1]=y[i]+(Vy[i]*dt);
	
	Vx[i+1]=Vx[i]+((-1.0)*exp(-y[i]/y0)*d[i]*V[i]*(Vx[i]-Vwind)*dt);
	
	Vy[i+1]=Vy[i]-(g*dt)+((-1.0)*exp(-y[i]/y0)*d[i]*V[i]*Vy[i]*dt);
	
	t[i+1]=t[i]+dt;

//	cout<<"x is "<<x[i]<<" y is "<<y[i]<<endl;

   if(y[i+1]<0){break;}
}
   //cout<<count<<endl; 
  tr = new TGraph(count,x,y);
  tr->SetLineColor(kRed);
  tr->GetXaxis()->SetTitle("Horizontal distance x, [m]");
  tr->GetYaxis()->SetTitle("Vertical distance y, [m]");
  tr->SetTitle("Angle Trajectories");
  tr->GetHistogram()->SetMaximum(80);
  TAxis*axis = tr->GetXaxis();
  axis->SetLimits(0,150);

  if(j==0){
  tr->Draw("Al");
}

   else
    tr->Draw("same");

    range[j] = x[count];
cout<<range[j]<<endl;

}

c = new TCanvas ("c","range",100,100,500,400);
c->Draw();

   
     gr = new TGraph(N,alpha,range);
     gr->SetTitle("Angles vs Range");
     gr->GetXaxis()->SetTitle("Angles, [degrees]");
     gr->GetYaxis()->SetTitle("Range, [m]");
     gr->SetLineColor(kBlue);
     gr->Draw("Al");


   
    
//leg = new TLegend(0.2,0.4,0.6,0.2);
//leg->AddEntry(tr,"angle trajectories","l");
//leg->AddEntry(gr,"Angle","l");
//leg->AddEntry(gr,"derivative using forward difference approximation","p");
//leg->AddEntry(gr2,"derivative using mid-point approximation","p");
//leg->Draw("same");
   








}