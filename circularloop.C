void circularloop(){
	

	const int n = 1000;
	const float N = 11;
	const float pi = 3.14159265;
	int i, j, k, l;
	float L = 3.;
	float Bx,By,Bz; 
	float x[2 * N] = {0.};
	float y[N] = {0.};
	float z[N] = {0.};
	float rx;
	float ry;
	float rz;
	float r;
	float dlx, dly, dlz;
	float R = 1.1;
	float dTheta = (2.0 * pi)/(n);
	float theta = 0.;
	float xw, yw, zw;

	float C = 3./(4.*pi);
  	
  	float dz = 0.1;
  	float dx = 0.1;

  	 gr = new TGraph();

    for (k = 0; k < N; k++)
    { 
    	z[k] = k * dz;
    	
    	for (i = 0; i < 2 * N; i++)
    	{ 
    		
    		if (i == N/2) continue;
    		x[i] = i * dx; 

			Bx = By = Bz = 0; 
    		for (l = 0; l < n; l++)
    		{ 
    			theta = l * dTheta;

    			dlx = -1.*R * dTheta * sin(theta);
    			dly = R * dTheta * cos(theta);
    			dlz = 0.;

    			xw = R * cos(theta);
    			yw = R * sin(theta);
    			zw = 0.;

    			rx = x[i] - xw;
    			ry = y[0] - yw;
    			rz = z[k] - zw;

    			r = sqrt((rx * rx) + (ry * ry) + (rz * rz));
    			if (r == 0) {
    				cout<<"k, i, l: "<<k<<", "<<i<<", "<<l<<endl;
    			cout<<"r: "<<r<<endl;}
    			

    			Bx= Bx + C * (dly * rz) / (r*r*r);
    			By = By - C * (dlx * rz) / (r*r*r);
    			Bz = Bz + C * (( dlx * ry -  dly * rx) / (r*r*r));
    		
    		}
    		
    		if (i == 0) gr->SetPoint(k , z[k], Bz);
    		gr->SetTitle("Magnetic Field due to a Wire; Distance From Wire (m); Magnetic Field (B)");
    		
    	}
    
    }

   
     gr->Draw("A*");

    exact = new TF1("exact sol mag field", "([0]*[1]*x*x)", -L, L);
	exact->SetParameter(0, 1.26 * pow(10,-6)); 
	exact->SetParameter(1, 1.0); 
	exact->SetLineColor(kBlue);
	exact->Draw("same");


	leg = new TLegend(0.2,0.3,0.5,0.2);
leg->AddEntry(gr,"Calculated Magnetic Field","p");
leg->AddEntry(exact,"exact solution","l");
leg->Draw("same");

   // hist->Draw("surf");
c = new TCanvas("c", "squarebox", 0,0,1000,350);
c->Draw();


dz = (2*L)/(N-1);
  dx = (2*L)/(N-1);

gStyle->SetOptStat(0);	
hist2 = new TH2D("hist1", "Magnetic field", N, -L-dx, L+dx, N, -L-dx, L+dx);
hist2->GetXaxis()->SetTitle("X");
  	hist2->GetYaxis()->SetTitle("Z");
	hist2->Draw("");

for (int i=0;i<N;i++){
	x[i] = -L + dx*i;

	for (int k=0;k<N;k++){

	z[k] = -L + dz*k;

//	if((fabs(x[i])==R) && (z[k] == 0)){
//	 continue;
//	}
	Bx[i] = 0; Bz[i] = 0; By[i] = 0;

	for(int l =0; l<n; l++){

		
    			theta = l * dTheta;

    			dlx = -1.*R * dTheta * sin(theta);
    			dly = R * dTheta * cos(theta);
    			dlz = 0.;

    			xw = R * cos(theta);
    			yw = R * sin(theta);
    			zw = 0.;

    			rx = x[i] - xw;
    			ry = y[0] - yw;
    			rz = z[k] - zw;

    			r = sqrt((rx * rx) + (ry * ry) + (rz * rz));
    			

    			Bx[i]= Bx[i] + C * ((dly * rz) / (r*r*r));
    			By[i] = By[i] - C * ((dlx * rz) / (r*r*r));
    			//Bz[k] = Bz[k] + C * (R * R * dTheta / pow((R * R + rz * rz), 3./2.));
    			Bz[i] = Bz[i] + C * (( dlx * ry -  dly * rx) / (r*r*r));


	}

	gr1 = new TArrow(x[i],z[k],x[i]+Bx[i],z[k]+Bz[i]);
			gr1->SetArrowSize(0.01);
			gr1->Draw();
	
	}
}
}
