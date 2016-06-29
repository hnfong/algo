program p10048;
{
@JUDGE_ID:  20044WC 10048 PASCAL "DaP/DyP"
}
var
	i,j,k : longint;
	c,s,q : longint;
	a,b,d : longint;
	w : array[1..100,1..100] of longint;
	casenum : longint;

function max(a,b: longint): longint; begin if a > b then max := a else max := b; end;

begin
	casenum := 0;
	while true do begin
		inc(casenum);
		readln(c,s,q);
		if (c=0) and (s=0) and (q=0) then break;
		if casenum > 1 then writeln;
		{ init }
		for i := 1 to 100 do
			for j := 1 to 100 do w[i,j] := 217483647;
		
		for i := 1 to s do begin
			readln(a,b,d);
			w[a,b] := d;
			w[b,a] := d;
		end;

		{ self }
		for i := 1 to 100 do w[i,i] := 0;

		{ warshall floyd }
		for k := 1 to c do begin
			for i := 1 to c do begin
				for j := 1 to c do begin
					if max(w[i,k],w[k,j]) < w[i,j] then begin
						w[i,j] := max(w[i,k],w[k,j]);
					end;
				end;
			end;
		end;
		
		{ queries }
		writeln('Case #', casenum);
		for i := 1 to q do begin
			readln(a,b);
			if w[a,b] < 217483647 then writeln(w[a,b]) else writeln('no path');
		end;
	end;
end.

