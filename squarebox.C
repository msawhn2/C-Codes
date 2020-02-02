void squarebox(){
	const int n = 8;
	float V[n][n], Vnew[n][n];
	float dV = 0;
	float Ex[n][n];
	float Ey[n][n];
	dx = fabs(-1. - 1.)/(n-1);
	dy = fabs(-1. - 1.)/(n-1);



	for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){

				if(j==0){
					V[i][0]=-1;
					Vnew[i][0]=-1;

				}	

				else if(j==n-1){
					V[i][n-1]=1;
					Vnew[i][n-1] = 1;

				}
				else{
					V[i][j]=0;
					Vnew[i][j]=0;
				}
				


			}


		}
//master 
		for(int k=0;k<10;k++){
			dV=0;
	
	for (int j=1;j<n-1;j++){
		for(int i=1;i<n-1;i++){

			Vnew[j][i] = 0.25*(V[j+1][i] + V[j-1][i] + V[j][i+1] + V[j][i-1]);
			dV = dV + fabs(Vnew[j][i] - V[j][i]);
			} 
}

for (int i=1;i<n-1;i++){

		Vnew[0][i] = (V[0][i-1] + V[0][i+1] + V[1][i] )/3;

		Vnew[n-1][i] = (V[n-1][i-1] + V[n-1][i+1] + V[n-2][i] )/3;

		 dV = dV + fabs(Vnew[0][i] - V[0][i]) + fabs(Vnew[n-1][i] - V[n-1][i]);
}

	if ((dV/(n*n)) <= 0.00001) { break; }

	for(int j=0;j<n;j++){
			for(int i=1;i<n-1;i++){

				V[j][i]=Vnew[j][i];

			}
		}
		//printing
for(int j=0;j<n;j++){

			for(int i=0;i<n;i++){

				cout<<V[j][i]<<" ";
		}
cout<<endl;
}
cout<<endl;
	
}
		hist = new TH2D("hist", "potential field", n, -1, 1, n, -1, 1);
	for (j = 0; j < n; j++){
		for (i = 0; i < n; i++){
			hist->SetBinContent(j+1, i+1, V[i][j]);
		}
	}
	gStyle->SetOptStat(0);
	hist->Draw("surf2");


c = new TCanvas("c", "squarebox", 0,0,1000,350);
c->Draw();

gStyle->SetOptStat(0);

	hist1 = new TH2D("hist1", "electric field", n, -1, 1, n, -1, 1);
	hist1->Draw("");
	for (j = 1; j < n-1; j++) {
		for (i = 1; i < n-1; i++) {

			Ex[j][i] = -1.0 * (V[j][i+1] - V[j][i-1])/(2*dx);
			Ey[j][i] = -1.0 * (V[j+1][i] - V[j-1][i])/(2*dy);


			gr = new TArrow(-1 + j * dx, -1 + i * dy, -1 + j * dx + Ex[j][i]/8, -1 + i * dy + Ey[j][i]/8);
			gr->SetArrowSize(0.01);
			gr->Draw();
		}
	}




}