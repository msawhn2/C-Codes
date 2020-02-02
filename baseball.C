void baseball(float dt=0.01, float v0=49.1744){
	
   const int n=3000;
   float pi = 3.14159261;
    float Vx[n],Vy[n],x[n],y[n],t[n],V[n];
    float Fdragx[n], Fdragy[n];
   // float B2 = 0.00003;
    //float m = 1; 
    float g =9.81;
    //Vx[0]=100;
    //Vy[0]=100;
    x[0]=0;
    y[0]=0;
    t[0]=0;
    float alpha = 45;
    //float v0=49.1744;
    float vd=35;
    float dx=5;
    int count =0;
    float V[0] = v0;
    //float Vwind = 4.4704;
    float Vwind=0;//4.4704;
    float d[n];
    float y0=10000;

    
    Vx[0] = v0*cos(alpha*pi/180);
    Vy[0] = v0*sin(alpha*pi/180);

   for(int i=0;i<n-1;i++){

    	//trajectory of baseball with wind 
    	count++;

    V[i] = sqrt ((pow(Vx[i]-Vwind),2)+pow(Vy[i],2));
    d[i]= 0.0039 + (0.0058/(1+exp((V[i]-vd)/dx)));
   // cout<<d[i]<<endl;
    
    x[i+1]=x[i]+(Vx[i]*dt);

	y[i+1]=y[i]+(Vy[i]*dt);
	
	Vx[i+1]=Vx[i]-(d[i]*V[i]*(Vx[i]-Vwind)*dt);

	//cout<<Vx[i]<<" "<<Vy[i]<<" "<<V[i]<< " "<<d[i]<<endl;

	
	Vy[i+1]=Vy[i]-(g*dt)-(d[i]*V[i]*Vy[i]*dt);
	
	t[i+1]=t[i]+dt;

   if(y[i+1]<0){break;}
}

gr1 = new TGraph(count,x,y);
     gr1->SetTitle("Trajectory of the baseball");
     gr1->GetXaxis()->SetTitle("x, [m]");
     gr1->GetYaxis()->SetTitle("y, [m]");
     gr1->SetLineColor(kBlue);
     gr1->Draw("Al");

 float Vwind=11.176;
    for(int i=0;i<n-1;i++){

    	//trajectory of baseball with wind 
    	count++;

    V[i] = sqrt ((pow(Vx[i]-Vwind),2)+pow(Vy[i],2));
    d[i]= 0.0039 + (0.0058/(1+exp((V[i]-vd)/dx)));
   // cout<<d[i]<<endl;
    
    x[i+1]=x[i]+(Vx[i]*dt);

	y[i+1]=y[i]+(Vy[i]*dt);
	
	Vx[i+1]=Vx[i]-(d[i]*V[i]*(Vx[i]-Vwind)*dt);

	//cout<<Vx[i]<<" "<<Vy[i]<<" "<<V[i]<< " "<<d[i]<<endl;

	
	Vy[i+1]=Vy[i]-(g*dt)-(d[i]*V[i]*Vy[i]*dt);
	
	t[i+1]=t[i]+dt;

   if(y[i+1]<0){break;}
}

//cout<<count<<endl;
//return;
     gr = new TGraph(count,x,y);
     //gr->SetTitle("Trajectory of the baseball");
     //gr->GetXaxis()->SetTitle("x, [m]");
     //gr->GetYaxis()->SetTitle("y, [m]");
     //gr->SetLineColor(kBlue);
     gr->Draw("same");
       //  gr1->Draw("same");

float Vwind=-11.176;
    for(int i=0;i<n-1;i++){

    	//trajectory of baseball with wind 
    	count++;

    V[i] = sqrt ((pow(Vx[i]-Vwind),2)+pow(Vy[i],2));
    d[i]= 0.0039 + (0.0058/(1+exp((V[i]-vd)/dx)));
   // cout<<d[i]<<endl;
    
    x[i+1]=x[i]+(Vx[i]*dt);

	y[i+1]=y[i]+(Vy[i]*dt);
	
	Vx[i+1]=Vx[i]-(d[i]*V[i]*(Vx[i]-Vwind)*dt);

	//cout<<Vx[i]<<" "<<Vy[i]<<" "<<V[i]<< " "<<d[i]<<endl;

	
	Vy[i+1]=Vy[i]-(g*dt)-(d[i]*V[i]*Vy[i]*dt);
	
	t[i+1]=t[i]+dt;

   if(y[i+1]<0){break;}
}
gr2 = new TGraph(count,x,y);
     //gr->SetTitle("Trajectory of the baseball");
     //gr->GetXaxis()->SetTitle("x, [m]");
     //gr->GetYaxis()->SetTitle("y, [m]");
     gr2->SetLineColor(kRed);
     gr2->Draw("same");

     leg = new TLegend(0.25,0.3,0.75,0.4);
leg->AddEntry(gr1,"without wind","l");
leg->AddEntry(gr,"with tail wind","l");
leg->AddEntry(gr2,"with head wind","l");
leg->Draw("same");
 










}