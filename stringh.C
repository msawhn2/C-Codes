void stringh(){
	const int nmax = 100;
	float dx = 0.01;
	float c = 300;
	float dt = 0.00003;
	float r2;
	float y[3][nmax];
	float x[nmax];
	const int time = 100;


	canvas = new TCanvas("canvas","wave",0,0,800,700);
	canvas->Draw();


	for(int i=0;i<nmax;i++){
		x[i] = i*dx;

	}


	for(int i=0; i<nmax-1;i++){

		
		y[1][i] = exp(-1000*(x[i] - 0.3)*(x[i] - 0.3));
		y[0][i] = exp(-1000*(x[i] - 0.3)*(x[i] - 0.3));
	}

		y[0][0] = 0;
		y[1][0] = 0;
		y[0][nmax-1] = 0;
		y[1][nmax-1] = 0;
		
	r2 = (dt*c/dx)*(dt*c/dx);

		for(int t=1;t<time-1;t++){

				for(int i=1;i<nmax-1;i++){

		// y[i][2] = r2*(y[i+1][1] + y[i-1][1]) + 2*(1.0-r2)*y[i][1] - y[i][0];
		// y[2][i] = r2*(y[1][i+1] + y[1][i-1]) + 2*(1.0-r2)*y[1][i] - y[0][i];
		y[2][i] = 2* (1-(r2*r2)) * y[1][i] - y[0][i] + (r2*r2) * (y[1][i+1] + y[1][i-1]);
	}

		for(int i=1;i<nmax-1;i++){


			y[0][i] = y[1][i];
			y[1][i] = y[2][i];

			// cout<<y[1][i];		

		
	}
   gr = new TGraph(nmax,x,y[1]);
   gr->SetMaximum(1.0);
   gr->SetMinimum(-1.0);
   gr->SetTitle("string with fixed ends");
   gr->GetYaxis()->SetTitle("Amplitude (y)");
   gr->GetXaxis()->SetTitle("Position (x)");		
   gr->Draw("AL");
      
     canvas->Update();
	}


  
}