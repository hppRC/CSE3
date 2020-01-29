program PL3A;
var i, j, n, a[1..100];
procedure initialize(n);
var i;
begin
   for i := 1 to n do
      read(a[i])
end;
begin
   read(n);
   if n <= 100 then
   begin
        initialize(n);
        write(a[3]);
        write(a[2]);
        write(a[1]);
   end;
end.
