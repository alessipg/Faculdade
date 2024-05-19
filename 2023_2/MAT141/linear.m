function [a, b, r2] = linear(X, Y)
  m = length(X);
  sx = sum(X)
  sy = sum(Y)
  sxy = sum(X .* Y)
  sx2 = sum(X.^2)

  alfa0 = (sx2 * sy - sxy * sx) / (m * sx2 - sx^2);
  alfa1 = (m * sxy - sx * sy) / (m * sx2 - sx^2);
  eqReta = alfa0 + alfa1 * X;

  ymedio = sum(Y) / m;
  st = sum((Y - ymedio).^2);
  sr = sum((Y - eqReta).^2);
  r2 = (st - sr) / st;

  b = alfa0;
  a = alfa1;
  printf("y = %.4fx + %.4f\n",a,b);
  printf("T(0) = %d\n",alfa0 + alfa1 * 22);
end

