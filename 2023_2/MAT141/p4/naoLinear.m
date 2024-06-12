function [a, b, r2] = naoLinear(x, y)
  m = length(x);
  %ajustar
  X = log(x);
  Y = log(y);

  sx = sum(X);
  sy = sum(Y);
  sxy = sum(X .* Y);
  sx2 = sum(X.^2);

  alfa0 = (sx2 * sy - sxy * sx) / (m * sx2 - sx^2);
  alfa1 = (m * sxy - sx * sy) / (m * sx2 - sx^2);
  eqReta = alfa0 + alfa1 * X;

  ymedio = sum(Y) / m;
  st = sum((Y - ymedio).^2);
  sr = sum((Y - eqReta).^2);
  r2 = (st - sr) / st;
  %ajustar

  a = exp(alfa0);
  b = alfa1;
  printf("s = %.4f * r ^ %.4f\n",a,b);
  printf("s(0.6666) = %.4f\n",a*0.6666^b);
  printf("sx = %.4f | sy = %.4f | sxy = %.4f | sx2 = %.4f\n",sx,sy,sxy,sx2);
end

