void cannon(float dt=0.2)
{
	const int n=500;
    float Vx[n],Vy[n],x[n],y[n],t[n],V[n];
    float xx[n],yy[n],VVx[n],VVy[n];
    float Fdragx[n], Fdragy[n];
    float B2 = 0.00003;
    float m = 1; 
    float g =9.8;
    //float theta = 3.14/3;
    float V[0]=100;
    xx[0]=0;
    yy[0]=0;
    VVx[0]=100;
    VVy[0]=100;
    Vx[0]=100;
    Vy[0]=100;
    //Vx[0]=V[0]*TMath::Cos(theta);
    //Vy[0]=V[0]*TMath::Sin(theta);
    x[0]=0;
    y[0]=0;
    t[0]=0;
    int count =0;



  

    for(int i=0;i<n;i++){
    
    count++;

     //without air resistance

	xx[i+1]=xx[i]+(VVx[i]*dt);

	yy[i+1]=yy[i]+(VVy[i]*dt);

	VVx[i+1] = VVx[i];

	VVy[i+1] = VVy[i] - g*dt;



   //with air resistance

    V[i]=sqrt((pow(Vx[i],2))+(pow(Vy[i],2)));

    Fdragx[i] = -1.0*B2*V[i]*Vx[i];

	Fdragy[i] = -1.0*B2*V[i]*Vy[i];


	x[i+1]=x[i]+(Vx[i]*dt);

	y[i+1]=y[i]+(Vy[i]*dt);
	
	Vx[i+1]=Vx[i]+((Fdragx[i]*dt)/m);
	
	Vy[i+1]=Vy[i]-(g*dt)+((Fdragy[i]*dt)/m);
	
	t[i+1]=t[i]+dt;

	cout<<Fdragy[i]<<" "<<Vy[i]<<" "<<VVy[i]<<endl;

    if(y[i+1]<0){break;}



	

	

}

gr1 = new TGraph(count,xx,yy);
//gr1->Draw("same");

gr = new TGraph(count,x,y);
gr1->SetTitle("Trajectory of cannon shell");
gr1->GetXaxis()->SetTitle("x, [m]");
gr1->GetYaxis()->SetTitle("y, [m]");

//Plot results:

c = new TCanvas("c","Trajectory of a cannon shell",10,10,800,700);
c->Draw();
gr1->SetLineColor(kBlue);
gr1->Draw();

gr->SetMarkerStyle(20);

gr->Draw("AP");
gr1->Draw("same*");



//adding legend
leg = new TLegend(0.2,0.4,0.6,0.2);
leg->AddEntry(gr1,"without air resistance","l");
leg->AddEntry(gr,"with air resistance","l");
leg->Draw("same");

 





}