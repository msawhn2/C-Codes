void energyplanet(float e=0.206){
	
	const int n=500;
 	     float dt=0.01;
 	     float pi = 3.1415;
 	     float Vx[n],Vy[n],x[n],y[n],r[n],KE[n],PE[n],E[n],V[n],t[n];
		float L[n]; 	    
 	     float Me = 6*pow(10,24);
 	     float a;
 	     a=1;
 	     float b;
 	     b=a*sqrt(1-(e*e));
 	     x[0]=a*(1+e);	//in AU
 	     y[0]=0;
 	     Vx[0]=0;	//in AU/yr
 	     Vy[0]=5;//2*pi;
 	     t[0]=0;
 	     float GMs = 4*pi*pi;

 	    
for(int i=0;i<n-1;i++){

 		r[i] = sqrt(x[i]*x[i] + y[i]*y[i]);

 		V[i] = sqrt(Vx[i]*Vx[i] + Vy[i]*Vy[i]);

 		Vx[i+1] = Vx[i] - ((4*pi*pi* x[i])/(r[i]*r[i]*r[i]))*dt;

 		Vy[i+1] = Vy[i] - ((4*pi*pi* y[i])/(r[i]*r[i]*r[i]))*dt;

 		x[i+1] = x[i] + Vx[i+1]*dt;

 		y[i+1] = y[i] + Vy[i+1]*dt;

 		t[i+1] = t[i]+dt;
 	
 	     KE[i] = 0.5*Me*V[i]*V[i];
 	     PE[i] = -1.0*(GMs*Me)/(r[i]);
 	     E[i] = KE[i] + PE[i];
 	     cout<<"E(t)"<<E[i]<<endl;
 	     L[i] = Me*(x[i]*Vy[i] - y[i]*Vx[i]);

}

	c2 = new TCanvas("c2","Angular momentum of a planet",10,10,800,700);
	c2->Draw(); 
    
    gr1 = new TGraph(n-1,t,KE);
	gr1->SetTitle("Energy vs time");
	gr1->GetXaxis()->SetTitle("t, [years]");
	gr1->GetYaxis()->SetTitle("E, [J]");
	gr1->SetLineColor(kRed);
	gr1->GetYaxis()->SetRangeUser(-500e24,500e24);
	gr1->Draw("AL");


	gr2= new TGraph(n-1,t,PE);
	gr2->SetLineColor(kBlue);
	gr2->Draw("same");

	gr3=new TGraph(n-1,t,E);
	gr3->SetLineColor(kGreen);
	gr3->Draw("same");


	leg = new TLegend(0.2,0.3,0.6,0.2);
	leg->AddEntry(gr1,"Kinetic Energy","l");
	leg->AddEntry(gr2,"Potential Energy","l");
	leg->AddEntry(gr3,"Total Energy","l");
	leg->Draw("same");

 	c1 = new TCanvas("c1","Angular momentum of a planet",10,10,800,700);
	c1->Draw(); 
	
	gr4 = new TGraph(n-1,t,L);
	gr4->SetTitle("Angular momentum vs time");
	gr4->GetXaxis()->SetTitle("t");
	gr4->GetYaxis()->SetTitle("L");
	gr4->SetLineColor(kRed);
	gr4->GetYaxis()->SetRangeUser(-300e24,300e24);
	gr4->Draw("AL");

	c3 = new TCanvas("c3","Angular momentum of a planet",10,10,800,700);
	c3->Draw(); 

	gr5 = new TGraph (n-1,x,y);
	gr5->SetTitle("Trajectory");
	gr5->GetXaxis()->SetTitle("x(AU)");
	gr5->GetYaxis()->SetTitle("y,(AU)");
	gr5->SetLineColor(kBlack);
	gr5->Draw("AL");


	const int m=3;
	int P[m];
	int P0[m];
	float d[m],A[m];

 
		for(int i=0;i<m;i++){
			P[i] = rand()%500;
			
			P0[i] = P[i] + 10;

			d[i] = sqrt((x[P[i]] - x[P0[i]])*(x[P[i]] - x[P0[i]]) + (y[P[i]] - y[P0[i]])*(y[P[i]] - y[P0[i]]));

			A[i] = 0.5*(r[P[i]])*d[i];

			l = new TLine(0,0,x[P[i]],y[P[i]]);

			l1 = new TLine(0,0,x[P0[i]],y[P0[i]]);

			l2 = new TLine(x[P[i]],y[P[i]],x[P0[i]],y[P0[i]]);

			l->SetLineColor(kGreen);

			l1->SetLineColor(kRed);

			l2->SetLineColor(kBlue);


			l->Draw("same");

			l1->Draw("same");

			l2->Draw("same");

			cout<<"P["<<i<<"]: "<<P[i]<<endl;

			cout<<"P0["<<i<<"]: "<<P0[i]<<endl;

			cout<<"A["<<i<<"]: "<<A[i]<<endl; 
		}

}