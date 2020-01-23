program PL2D;
var n, sum;
procedure result(n, m, l);
var temp;
begin
    temp := m * l;
    sum := sum + n * m + temp;
end;
procedure result;
write(sum);
begin
   n := 10;
   sum := 0;
   while n > 0 do
   begin
      result(n, n * 2, n + 2);
      n := n - 1
   end;
   result
end.
