program pfib;
var
	i,j,k,l : longint;
function fib(x:longint):longint;
begin
	if x=0 then fib := 0;
	if x= 1 then fib := 1;
	if x > 1 then fib := fib(x-1) + fib(x-2);
end;

begin
	j := 0;
	k := 1;
	for i := 1 to 45 do begin
		writeln(j);
		l := j + k;
		j := k;
		k := l;
	end;
end.
