void curveball(float dt=0.01){
	 
	float b = 0.00041; 
	float pi=3.14159265;
	float g=9.81;
	const int n =3000;
	float Vx[n],Vy[n],V[n],x[n],y[n],z[n],t[n],Vz[n];
	float alpha = 55;
    float v0 = 31.2928;
    x[0]=0;
    y[0]=0;
    z[0]=0;
    t[0]=0;
     
    float vd=35;
    float dx=5;
    int count =0;
    float V[0] ;
    float Vwind = 0;//4.4704;
    float d[n];
    float y0=10000;
    

    v[0]=v0;
	float w = 30*(2*pi);
    Vx[0] = v0*sin((alpha*pi)/180);
    Vy[0] = v0*cos((alpha*pi)/180);
    Vz[0] = 0;

    for(int i=0;i<n-1;i++){

count++;
//   V[i] = sqrt ((pow(Vx[i]-Vwind),2)+pow(Vy[i],2));
    
    V[i] = sqrt(Vx[i]*Vx[i]+Vy[i]*Vy[i]);
  
    d[i]= 0.0039 + (0.0058/(1+exp((V[i]-vd)/dx)));

    
   x[i+1]=x[i]+(Vx[i]*dt);

  y[i+1]=y[i]+(Vy[i]*dt);

  z[i+1]= z[i]+(Vz[i]*dt);

  
//  Vx[i+1]=Vx[i]- d[i]*V[i]*(Vx[i]-Vwind)*dt;
  Vx[i+1]=Vx[i]- d[i]*V[i]*Vx[i]*dt;

  Vy[i+1]=Vy[i]-(g*dt)-(d[i]*V[i]*Vy[i]*dt);

  Vz[i+1]=Vz[i] -  b*w*Vx[i]*dt;
  
  
  t[i+1]=t[i]+dt;

   if(y[i+1]<0){break;}




}

 c = new TCanvas ("c","curve ball trajectories",100,100,900,400);
 c->Divide(3);

c_1->cd();
 xy= new TGraph (count, x,y);
 xy->SetTitle("xy trace");
     xy->GetXaxis()->SetTitle("x, [m]");
     xy->GetYaxis()->SetTitle("y, [m]");
     xy->SetLineColor(kBlue);
     xy->Draw();
 

 yz = new TGraph (count,y,z);
 c_2->cd();
 yz->SetTitle("yz trace");
     yz->GetXaxis()->SetTitle("y, [m]");
     yz->GetYaxis()->SetTitle("z, [m]");
     yz->SetLineColor(kBlue);
     yz->Draw();

c_3->cd();
 xz = new TGraph (count,x,z);
 xz->SetTitle("xz trace");
     xz->GetXaxis()->SetTitle("x, [m]");
     xz->GetYaxis()->SetTitle("z, [m]");
     xz->SetLineColor(kBlue);
     xz->Draw();

 




}