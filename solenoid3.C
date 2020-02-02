void solenoid3(){
	

	const int n = 1000;
	const int N = 10;
	const int turns = 80;
	const float pi = 3.14159265;
	int i, j, k, l;
	// float L = 10.;
	float Bx,By,Bz; 
	float x[2*turns] = {0.};
	// float y[N] = {0.};
	float y[turns] = {0.};
	float z=0;
	float rx;
	float ry;
	float rz;
	float r;
	float dlx, dly, dlz;
	float R = 0.555;
	float dTheta = (2 * pi)/(N-1);
	float L = 2.0*R;
	float theta = 0.;
	float xw, yw, zw;
	float cz = 0.1*R;
	float dzw = cz/N;

	float C = 1./(4.*pi);
  	
  	 float dz,dx,dy;
dy = 0.1;
  dx = (2.*L)/(N-1);
dz =(2.*L)/(N-1);//0.1;
  	
c = new TCanvas("c", "B field", 0,0,800,700);
c->Draw();

// dz = (2*L)/(N-1);
//   dx = (2*L)/(N-1);


gStyle->SetOptStat(0);	
hist2 = new TH2D("hist1", "Magnetic field in the x-y plane", N, -L-dx, L+dx, N, -L-dx, L+dx);
cout<<-L+dx<<endl;
hist2->GetXaxis()->SetTitle("x");
  	hist2->GetYaxis()->SetTitle("y");
	hist2->Draw();

for (int i=0;i<N;i++){
	x[i] = -L + dx*i;

	for (int k=0;k<N;k++){

	y[k] = -L + dz*k;
	// float cz = k;

	if((fabs(x[i])==R) && (y[k] > -1.0*R) &&(y[k] < R)){
	 continue;
	}
	// if((fabs(x[i])==R) && (y[k] == 0)){
	//  continue;
	// }
	Bx[i] = 0; Bz[i] = 0; By[i] = 0;

	for(int l =0; l<n; l++){

		
    			theta = l * dTheta;

    			dlx = -1.*R * dTheta * sin(theta);
    			dly = R * dTheta * cos(theta);
    			dlz = R * dTheta * tan(theta);

    			xw = R * cos(theta);
    			yw = R * sin(theta);
    			zw = 0;

    			rx = x[i] - xw;
    			ry = y[k] - yw;
    			rz = z - zw;

    			r = sqrt((rx * rx) + (ry * ry) + (rz * rz));
    			

    			Bx[i]= Bx[i] + C * ((dlz * ry) / (r*r*r));
    			By[i] = By[i] - C * (((dlz * rx)-(dlx*rz)) / (r*r*r));
    			//Bz[k] = Bz[k] + C * (R * R * dTheta / pow((R * R + rz * rz), 3./2.));
    			Bz[i] = Bz[i] + C * ((dly*rx)/ (r*r*r));
    			

	}

	// gr1 = new TArrow(x[i],z[k],x[i]+Bx[i]/1000,z[k]+Bz[i]/1000);
gr1 = new TArrow(x[i],y[k],x[i]+Bx[i]/2000,y[k]+By[i]/2000);
//	gr1 = new TArrow(x[i],y[k],x[i]+0.05,y[k]);
	 // gr1->GetXaxis()->SetLimits(0,5);
			gr1->SetArrowSize(0.03);
			gr1->Draw();
	
	}
}


}

