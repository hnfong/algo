program waring;
var
	i,j,k,n,m : longint;
	w : array[1..1000] of longint;
	o : array[1..100] of longint;
	p : longint;
function war(n,k : longint) : boolean;
label hell;
var
	i,j : longint;
	e,f : longint;
	ret : boolean;
begin
	ret:= false;
	if (k = 0) and (n > 0) then begin
		goto hell;
	end;
	if n = 0 then begin
		ret := true;
		goto hell;
	end;
	e := trunc(power(n, 1/m))+1;
	f := trunc(power(n/k, 1/m));
	for i := e downto f do begin
		j :=power(i,m); 
		if  j > n then continue;
		if war(n-j,k-1) then begin
			inc(p);
			o[p] := i;
			ret := true;
			goto hell;
		end;
	end;
	hell:
	war := ret;
end;

begin
	readln(n,k,m);	
	p := 0;
	for i := 1 to k do o[i] := 0;
	if (war(n,k)) then begin
		for i := 1 to k-1 do write(o[i], ' ');writeln(o[k])
	end else writeln('NO SOLUTION');
end.
