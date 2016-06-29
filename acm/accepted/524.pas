program p524;
{
@JUDGE_ID:  20044WC 524 PASCAL "Recursive"
MARGINAL Runtime...!!! I wonder what will happen when this is rejudged....
Code agressively optimized!! So might not work as expected if you change things around...
}
const
	hc : array[2..11] of integer = (
		3,5,7,11,13,17,19,23,29,31
	);
var
	n : integer;
	u : array[1..16] of boolean;
	a : array[1..16] of integer;
	l : integer;
	mi : integer;
	t : integer;
procedure p (x: integer);var i : integer;
begin
	inc(l);
	a[l] := x;
	if l = n then begin
		for i := 2 to 11 do begin
			if hc[i] = a[n]+1 then begin
				for i := 1 to n-1 do begin
					write(a[i],' ');
				end;writeln(a[n]);
				break;
			end;
		end;
	end else begin
		u[x] := true;
		t := 3-x; if (t > 0) and (t <= n) then if (u[t] = false) then p(t);
		t := 5-x; if (t > 0) and (t <= n) then if (u[t] = false) then p(t);
		t := 7-x; if (t > 0) and (t <= n) then if (u[t] = false) then p(t);
		t := 11-x; if (t > 0) and (t <= n) then if (u[t] = false) then p(t);
		t := 13-x; if (t > 0) and (t <= n) then if (u[t] = false) then p(t);
		t := 17-x; if (t > 0) and (t <= n) then if (u[t] = false) then p(t);
		t := 19-x; if (t > 0) and (t <= n) then if (u[t] = false) then p(t);
		t := 23-x; if (t > 0) and (t <= n) then if (u[t] = false) then p(t);
		t := 29-x; if (t > 0) and (t <= n) then if (u[t] = false) then p(t);
		t := 31-x; if (t > 0) and (t <= n) then if (u[t] = false) then p(t);
		u[x] := false;
	end;
	dec(l);
end;

begin
	mi := 0;
	while not eof do begin
		fillchar(a,sizeof(a),0);
		fillchar(u,sizeof(u),0);
		readln(n);
		inc(mi);
		if mi > 1 then writeln;
		writeln('Case ',mi,':');
		if (n = 1) or (n mod 2 <> 1) then p(1);
	end;
end.

