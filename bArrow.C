void bArrow(){
	
float L = 10.;
const int N=10;
float dz = 0.1;

// for(int k =0;k<N;k++){

// z[k] = k*dz;
// }
  exact = new TF1("exact sol mag field", "([0]*[1]*x*x)/(sqrt(2*(x*x + [2]*[2])))", -L, L);
	exact->SetParameter(0, 1.26 * pow(10,-6)); 
	exact->SetParameter(1, 1.0); 
	exact->SetParameter(2,[0 1 2 3 4 5 6 7 8 9]); 
	exact->SetLineColor(kBlue);
	exact->Draw();

	/*const int n = 50;
	const float N = 10;
	const float pi = 3.14159265;
	int i, j, k, l;
	float Bx;
	float By;
	float Bz;
	float x[2*N] = {0.};
	float y[N] = {0.};
	float z[2*N] = {0.};
	float rx;
	float ry;
	float rz;
	float r;
	float dlx, dly, dlz;
	float R = 1.;
	float dTheta = (2.0 * pi)/(n);
	float theta = 0.;
	float xw, yw, zw;


	float C = 1./(4.*pi);
  	
  	float dz = 2;
  	float dx = 2;

  	hist = new TH2D("hist", "eField arrows", N, -10, 10, N, -10, 10);
  	hist->GetXaxis()->SetTitle("X");
  	hist->GetYaxis()->SetTitle("Z");
  	hist->Draw("");
  	gStyle->SetOptStat(0);

    for (k = 0; k < N; k++)
    { 
    	z[k] = -N + k * dz;
    	
    	for (i = 0; i < N; i++)
    	{ 
    		x[i] = -N + i * dx; 

			Bx = By = Bz = 0; 

    		for (l = 0; l < n; l++)
    		{ 
    			theta = l * dTheta;

    			dlx = -1.* R * dTheta * sin(theta);
    			dly = R * dTheta * cos(theta);
    			dlz = 0.;

    			xw = R * cos(theta);
    			yw = R * sin(theta);
    			zw = 0.;

    			rx = x[i] - xw;
    			ry = y[0] - yw;
    			rz = z[k] - zw;

    			r = sqrt((rx * rx) + (ry * ry) + (rz * rz));

    			Bx = Bx + C * ((dly * rz)-(dlz *ry)) / (r*r*r);
    			By = By - C * ((dlz*rx)-(dlx * rz)) / (r*r*r);
    			Bz = Bz + C * (( dlx * ry -  dly * rx) / (r*r*r));
    		
    		}
    		ar = new TArrow(x[i], z[k], x[i] + Bx, z[k] + Bz);
    		ar->SetArrowSize(0.02);
    		ar->Draw();
    	}
    }
*/
}