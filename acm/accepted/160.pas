program p160;
{
@JUDGE_ID:  20044WC 160 PASCAL "DaP/DyP"
}
var
	i,j,k,nump : longint;
	p : array [1..100] of longint;
	a : array [1..100,1..100] of longint;  { a[n,p] }
	ans : array[1..100] of longint;
	n : longint;
	t : boolean;
begin
	{ preprocess }
	fillchar(p, sizeof(p), 0);
	fillchar(a, sizeof(a), 0);

	nump := 0;
	for i := 2 to 100 do begin
		t := true;
		for j := 2 to trunc(sqrt(i)) do begin
			if (i mod j) = 0 then begin
				t := false;
				break;
			end;
		end;

		if t then begin
			inc(nump);
			p[nump] := i;
		end;
	end;

	for i := 2 to 100 do begin
		n := i;
		for j := 1 to nump do begin
			while (n mod p[j]) = 0 do begin
				inc(a[i,j]);
				n := n div p[j];
			end;
		end;
	end;
	
	{ i/o }
	while true do begin
		fillchar(ans,sizeof(ans),0);
		readln(n);
		if n = 0 then break;
		if (n < 2) or (n > 100) then continue;
		for i := 2 to n do begin
			for j := 1 to nump do begin
				ans[j] := ans[j] + a[i,j];
			end;
		end;
		for k := nump downto 1 do begin
			if ans[k] > 0 then break;
		end;

		write(n:3, '! =');
		for i := 1 to k do begin
			write(ans[i]:3);
			if ((i mod 15) = 0) and (i <> k) then begin writeln; write('      '); end;
		end;writeln;
	end;
end.
