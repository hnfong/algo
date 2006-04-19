program x412;
{
	@JUDGE_ID:  20044WC 412 PASCAL "gcd ><"
}
var
	n : longint;
	i,j,k : longint;
	x : longint;
	match : longint;
	unmatch : longint;
	p : array[1..4000] of word; { primes }
	np : longint; {number of primes}
	inp : array[1..50] of longint;
function gcd(a,b:integer):integer;
begin
   while (a>0) and (b>0) do
   begin
      if (a>b) then
	 a := a mod b
      else 
	b := b mod a;
   end;
   if (a=0) then
	gcd := b
   else
      gcd := a;
end; 

function nc2(n : longint) : longint;
begin
	nc2 := (n*(n-1)) div 2
end;

begin
	for i := 2 to 32768 do begin
		x := 1;
		for j := 2 to trunc(sqrt(i)) do begin
			if (i mod j) = 0 then begin x := 0; break; end;
		end;
		if (x > 0) then begin
			np := np + 1;
			p[np] := i;
		end;
	end;


	while true do begin
		readln(n);
		if n = 0 then break;
		match := 0;
		fillchar(inp, sizeof(inp), 0);
		for i := 1 to n do begin readln(inp[i]); end;

		for i := 1 to n do begin
			for j := 1 to n do begin
				if (j >= i) then continue;
				if gcd(inp[i], inp[j]) > 1 then inc(match);
			end;
		end;
		unmatch := nc2(n) - match;
		if (unmatch = 0) then writeln('No estimate for this data set.') else writeln(sqrt(6 / unmatch * nc2(n)):0:6);
	end;
end.

