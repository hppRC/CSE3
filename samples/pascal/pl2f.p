program PL0D;
var n, temp;
procedure fact;
var m;
begin
   if n <= 1 then
      temp:=1
   else
   begin
      while n > 0 do
      begin
         if n >= 10 then
         begin
            temp:=n;
            n:=n-1;
            write(temp);
         end
         else
         begin
            m:=n;
            n:=n-1;
            temp:=temp+m
         end;
      end;
   end
end;
begin
    read(n);
    fact;
    write(temp);
end.
