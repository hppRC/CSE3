program PL3B;
var a[2..100],i,n;
procedure initialize;
var i;
   for i := 2 to 100 do
      a[i] := 0;
procedure check(p);
var i;
begin
   i := p;
   while i <= 100 do
   begin
	   a[i] := 1;
	   i := i + p;
   end
end;
begin
   initialize;
   read(n);
   if n <= 100 then
   begin
      for i := 2 to n do
      begin
         if a[i] = 0 then
         begin
            write(i);
            check(i);
         end;
      end;
   end;
end.
