program p855;
{
	@JUDGE_ID: 20044WC 855 PASCAL "Find the Median"
}
var
	i,j,k,t : longint;
	n : longint;
	hc : array[1..10] of integer;
	st, av : array[1..50000] of longint;
	tc : longint;
	ni : longint;
	ns, na,nf : longint;
begin
	hc[1] := 1;
	for i := 2 to 10 do begin hc[i] := (hc[i-1]+1)*2-1; end;
	readln(tc);
	for ni := 1 to tc do begin
		readln(ns, na, nf);
		for i := 1 to nf do begin
			readln(st[i], av[i]);
		end;
		
		for k := 10 downto 1 do begin
			for i := 1 to nf do begin
				t := st[i];
				j := i;
				while (j-k > 0) and (st[j-k] > t) do begin
					dec(j, k);
					st[j+k] := st[j];
				end;
				st[j] := t;
			end;
		end;

		for k := 10 downto 1 do begin
			for i := 1 to nf do begin
				t := av[i];
				j := i;
				while (j-k > 0) and (av[j-k] > t) do begin
					dec(j, k);
					av[j+k] := av[j];
				end;
				av[j] := t;
			end;
		end;
		{for i := 1 to nf do writeln(st[i], ' ', av[i]);}
		writeln('(Street: ',st[nf div 2 + nf mod 2],', Avenue: ',av[nf div 2 + nf mod 2],')');
	end;
end.
