program p686;
{
@JUDGE_ID: 20044WC 686 PASCAL
}
const hc = true;
var
	i,j,k,p,z : longint;
	b : boolean;
	v  : array[1..4000] of longint;
	u  : array[1..32768] of boolean;
begin
	p := 0;
	for i := 2 to 32768 do begin
		b := true;
		for j := 2 to trunc(sqrt(i)) do begin
			if i mod j = 0 then begin
				b := false;
				break;
			end;
		end;
		if b then begin
			inc(p);
			v[p] := i;
		end;
		u[i] := b;
	end;
	while true do begin
		z := 0;
		readln(i);
		if i = 0 then break;
		for j := 1 to p do begin
			if v[j]>i div 2 then break;
			if u[i-v[j]] then inc(z);
		end;
		writeln(z);
	end;
end.
