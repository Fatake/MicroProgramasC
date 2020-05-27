long pasos = 100000;
double base;
int main ()
{ 
       int i; 
      double x, pi, suma = 0.0;
      base = 1.0/(double) pasos;
      for (i=0;i< pasos; i++)
      {
            x = (i+0.5)*base;
            sum = sum + 4.0/(1.0+x*x);
      }
      pi = base * sum;
}
