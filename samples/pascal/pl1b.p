program PL1A;
var n, temp;
procedure fact(n, m);
begin
      if n <= 1 then
	 temp:=1
      else
      begin
	 fact(n - 1, m);
	 temp := temp * n
      end
end;
begin
   read(n);
   fact(n, 1);
   write(temp)
end.
