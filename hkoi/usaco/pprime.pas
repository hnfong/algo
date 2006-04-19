{
PROG: pprime
ID: sydneyf1
}

program pprime;
var
	a,b : longint;
	i,j,k,l : longint;
procedure isprime(x:longint);
var j: longint;q:boolean;
begin
	if (x < a) or (x > b) then exit;
	q := true;
	for j := 2 to trunc(sqrt(x)) do begin
		if (x mod j) = 0 then begin q := false; break; end;
	end;
	if q then writeln(x);
end;

begin
	assign(input,'pprime.in');
	reset(input);
	assign(output,'pprime.out');
	rewrite(output);
	readln(a,b);

	{ 1 }
	isprime(2);
	isprime(3);
	isprime(5);
	isprime(7);

	isprime(11);
	{ 3 }
	for i := 1 to 9 do begin
		for j := 0 to 9 do begin
			isprime(i*100+j*10+i);
		end;
	end;
	{ 5 }
	for i := 1 to 9 do
		for j := 0 to 9 do
			for k := 0 to 9 do
				isprime(i*10000+j*1000+k*100+j*10+i);
	{ 7 }
	for i := 1 to 9 do
		for j := 0 to 9 do
			for k := 0 to 9 do
				for l := 0 to 9 do
				isprime(i*1000000+j*100000+k*10000+l*1000+k*100+j*10+i);
	close(output);
	close(input);
	exit;
end.
