program PL0D;
var n, temp;
procedure fact;
var m;
begin
   if n <= 1 then
      temp:=1
   else
   begin
      if n >= 5 then
      begin
         temp:=1;
         n:=n-1;
         fact;
      end
      else
      begin
         m:=n;
         n:=n-1;
         fact;
         temp:=temp*m
      end;
   end
end;
begin
    read(n);
    fact;
    write(temp);
end.
