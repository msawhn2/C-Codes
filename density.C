void density(float dt=1)
{   
	const int n=200;
    float Vx[n],Vy[n],x[n],y[n],t[n],V[n];
    float xx[n],yy[n],VVx[n],VVy[n];
    float Fdragx[n], Fdragy[n]; 
    float B2 = 0.00003;
    float m = 1.5; 
    float g =9.8;
    float theta = 3.14/3;
    //float V[0]=100;
    //Vx[0]=V[0]*TMath::Cos(theta);
    //Vy[0]=V[0]*TMath::Sin(theta);
    xx[0]=0;
    yy[0]=0;
    VVx[0]=10;
    VVy[0]=10;
    Vx[0]=500;
    Vy[0]=500;
    x[0]=0;
    y[0]=0; 
    t[0]=0;
   float y0=1000;



  c = new TCanvas("c","Trajectory of a cannon shell",10,10,800,700);
  c->Draw();
//int count = 0;
    for(int i=0;i<n-1;i++){
//count++;

    //without air resistance and without density correction
    //xx[i+1]=xx[i]+(VVx[i]*dt);

	//yy[i+1]=yy[i]+(VVy[i]*dt);

	//VVx[i+1] = VVx[i];

	//VVy[i+1] = VVy[i] - g*dt;

    //with air resistance but without density correction
     V[i]=sqrt((pow(Vx[i],2))+(pow(Vy[i],2)));

    Fdragx[i] = -B2*V[i]*Vx[i];

	Fdragy[i] = -B2*V[i]*Vy[i];


	x[i+1]=x[i]+(Vx[i]*dt);

	y[i+1]=y[i]+(Vy[i]*dt);
	
	Vx[i+1]=Vx[i]+((Fdragx[i]*dt)/m);
	
	Vy[i+1]=Vy[i]-(g*dt)+((Fdragy[i]*dt)/m);
	
	t[i+1]=t[i]+dt;

	cout<<x[i]<<" "<<y[i]<<endl;
}


gr1 = new TGraph(n,x,y);
//gr->SetTitle("Trajectory of cannon shell with air density");
//gr->GetXaxis()->SetTitle("x, [m]");
//gr->GetYaxis()->SetTitle("y, [m]");
gr1->SetLineColor(kRed);
//gr1->Draw("Al");



for(int i=0;i<n;i++){
   //with air resistance and density correction

    V[i]=sqrt((pow(Vx[i],2))+(pow(Vy[i],2)));

    Fdragx[i] = -1.0*exp(-1.0*y[i]/y0)*B2*V[i]*Vx[i];

	Fdragy[i] = -1.0*exp(-1.0*y[i]/y0)*B2*V[i]*Vy[i];


	x[i+1]=x[i]+(Vx[i]*dt);

	y[i+1]=y[i]+(Vy[i]*dt);
	
	Vx[i+1]=Vx[i]+((Fdragx[i]*dt)/m);
	
	Vy[i+1]=Vy[i]-(g*dt)+((Fdragy[i]*dt)/m);
	
	t[i+1]=t[i]+dt;

	cout<<Vx[i]<<" "<<Vy[i]<<endl;

//if(y[i+1]<0) {break;}

	

	

}

//gr1 = new TGraph(n+1,x,y);
//gr1->SetTitle("Trajectory of cannon shell with air density");
//gr1->GetXaxis()->SetTitle("x, [m]");
//gr1->GetYaxis()->SetTitle("y, [m]");
//gr1->SetLineColor(kRed);
//gr1->Draw()


//plot results
//gr2=new TGraph(n+1,xx,yy)
gr = new TGraph(n,x,y);
gr->SetTitle("Trajectory of cannon shell with air density");
gr->GetXaxis()->SetTitle("x, [m]");
gr->GetYaxis()->SetTitle(" y, [m]");
gr->SetLineColor(kBlue);
gr->Draw("Al");
gr1->Draw("same");
//gr2->Draw("same")
//exact solution



//adding legend
leg = new TLegend(0.25,0.3,0.75,0.4);
leg->AddEntry(gr1,"with air resistance but without air density correction","l");
leg->AddEntry(gr,"with air resistance and density correction","l");
leg->Draw("same");
 


}