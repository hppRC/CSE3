program PL3B;
var a[2..100],i,n;
procedure initialize;
var i;
   for i := 2 to 100 do
      a[i] := 0;
procedure test(n);
var x[1..100];
begin
    x[n] := 10;
    write(x[n]);
end;
begin
   initialize;
   read(n);
   if n <= 100 then
   begin
        test(5);
   end;
end.
