{
//   example of macro to read data from an ascii file and
//   create a root file with an histogram and an ntuple.
 
   gROOT->Reset();

   FILE *fp = fopen("/home/user/Amani/ha.txt","r");
   
   Float_t Decay,N ,NA,Chain,Z_f ,N_f ,Zc,N_c ,J_c ,Jf,M_Jc,Fission,Ex_i ,Ex_f,Ep_Lab,Ap_Lab ;
    
   Int_t ncols;
   Int_t nlines = 0;     
   TFile *f = new TFile("analyse.root","RECREATE");
   TH1F *h1 = new TH1F("h1","x distribution",100,-4,4);
   TNtuple *data = new TNtuple("data","data from ascii file","Decay:N :NA:Chain:Z_f:N_f:Zc:N_c:J_c:Jf:M_Jc :Fission:Ex_i:Ex_f:Ep_Lab :Ap_Lab ");

   while (1) {
     fscanf(fp,"%f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f ",&Decay ,&N,&NA ,&Chain,&Z_f,&N_f,&Zc,&N_c,&J_c,&Jf,&M_Jc ,&Fission ,&Ex_i ,&Ex_f ,&Ep_Lab,&Ap_Lab);
      if (!in.good()) break;    
       if (nlines < 5) printf("Decay =%8f, N =%8f, N=%8f, Chain=%8f, Z_f=%8f, N_f =%8f,  Zc=%8f, N_c =%8f, J_c=%8f, Jf =%8f, M_Jc =%8f, Fisson =%8f, Ex_i=%8f, Ex_f=%8f, Ep_Lab =%8f ,Ap_Lab =%8f",Decay,N ,NA,Chain,Z_f ,N_f ,Zc,N_c ,J_c ,Jf,M_Jc,Fission,Ex_i ,Ex_f,Ep_Lab,Ap_Lab );
      h1->Fill(Decay,N ,NA,Chain,Z_f ,N_f ,Zc,N_c ,J_c ,Jf,M_Jc,Fission,Ex_i ,Ex_f,Ep_Lab,Ap_Lab )
      data->Fill(Decay,N ,NA,Chain,Z_f ,N_f ,Zc,N_c ,J_c ,Jf,M_Jc,Fission,Ex_i ,Ex_f,Ep_Lab,Ap_Lab );
      nlines++;
   }
   printf(" found %d points\n",nlines);
   
   fclose(fp);

   f->Write();
}






















