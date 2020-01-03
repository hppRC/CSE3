program PL1A;
var n, temp;
procedure fact(n, m);
var k, l;
begin
    k := 0;
    l := 2;
      if n <= 1 then
	 temp:=1
      else
      begin
	 fact(n - 1, m + k + l);
	 temp := temp * n
      end
end;
begin
   read(n);
   fact(n, 1);
   write(temp)
end.
