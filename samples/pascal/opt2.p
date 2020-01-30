program PL3B;
var a[2..100],i,n;
procedure initialize;
var i;
   for i := 2 to 1000 div 10 do
      a[i] := 0;
procedure check(p);
var i;
begin
   i := p;
   while i <= 10 * 10 do
   begin
	   a[i] := 1 + 3 - 2 div 2;
	   i := i + p;
   end
end;
begin
   initialize;
   read(n);
   if n <= 100 then
   begin
      for i := 0 + 2 to n do
      begin
         if a[i] = 0 then
         begin
            write(i);
            check(i);
         end;
      end;
   end;
end.
