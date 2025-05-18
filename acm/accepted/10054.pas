program p10054;
{
	@JUDGE_ID: 20044WC PASCAL 10054
}
label hell;
label sucessfulmerge;
const
	debug = false;
var
	i,j,k,n,tc,ti : longint;
	w : array[1..1000,1..2] of longint;
	u : array[1..1000] of boolean;
	l : array[1..2000,1..2] of longint;
	h : array[1..1000] of longint;
	vn,ve : longint;
	q : boolean;
	euler : array[1..50] of longint;
	goodmerge : boolean;
procedure merger(x:longint);
var a,b,c,d,i,j,k : longint;
begin
	if debug then writeln('merger', w[l[x,1],1], ' ', w[l[x,1],2]);
	a := 0;
	for i := 2 to vn do begin
		k := l[h[i],2];
		if k = 0 then continue;
		while true do begin
			if (w[l[x,1],2] = w[l[k,1],1]) and (a = 0) then begin
				a := k;
				b := l[x,2];
				l[x,2] := k;
			end;
			if l[k,2] = a then begin
				l[k,2] := b;
				break;
			end;
			k := l[k,2];
			if (k = l[h[i],2]) and (a = 0) then break;
		end;
		if a <> 0 then begin
			l[h[i],2] := 0;
			goodmerge := true;
			break;
		end;
	end;
end;

begin
	readln(tc);
	for ti := 1 to tc do begin
		fillchar(u,sizeof(u),0);
		fillchar(euler,sizeof(euler),0);
		fillchar(l,sizeof(l),0);
		vn := 0;
		ve := 0;

		writeln('Case #', ti);
		readln(n);
		for i := 1 to n do begin
			readln(w[i,1],w[i,2]);
			inc(euler[w[i,1]]);
			inc(euler[w[i,2]]);
		end;
		{ check uler }
		q := false;
		for i := 1 to 50 do begin
			if euler[i] mod 2 = 1 then begin
				writeln('some beads may be lost');
				q := true;
				break;
			end;
		end;
		if q then goto hell ;
		{ finding links }
		while true do begin
			{ find an unused to start }
			k := 0;
			for i := 1 to n do begin
				if not u[i] then begin
					k := i;
					break;
				end;
			end;
			if k = 0 then break;

			{ find a chain }
			j := k;
			u[j] := true;
			inc(vn);
			inc(ve);
			h[vn] := ve;
			l[ve,1] := 1;
			while true do begin
				l[ve,2] := ve + 1;
				inc(ve);
				l[ve,1] := j;
				q := false;
				for i := 1 to n do begin
					if not u[i] then begin
						if w[i,1] = w[j,2] then begin
							q := true;
							j := i;
							u[j] := true;
							break;
						end;
						if w[i,2] = w[j,2] then begin
							q := true;
							j := i;
							k := w[j,2];
							w[j,2] := w[j,1];
							w[j,1] := k;
							u[j] := true;
							break;
						end;
					end;
				end;
				if q = false then break;
			end;
			l[ve,2] := l[h[vn],2];
		end;
		{ to merge }
		k := l[h[1],2];
		sucessfulmerge:
		goodmerge := false;
		while k > 0 do begin
			if euler[w[l[k,1],2]] > 2 then begin
				merger(k);
				if goodmerge then break;
			end;
			k := l[k,2];
			if k = l[h[1],2] then break;
		end;
		if goodmerge then goto sucessfulmerge;

		{ count }
		j := 0;
		k := l[h[1],2];
		while k > 0 do begin
			inc(j);
			k := l[k,2];
			if k = l[h[1],2] then break;
		end;
		if j < n then begin
			writeln('some beads may be lost');
			if not debug then goto hell;
		end;
		{ output }
		k := l[h[1],2];
		while k > 0 do begin
			writeln( w[l[k,1], 1], ' ', w[l[k,1], 2]);
			k := l[k,2];
			if k = l[h[1],2] then break;
		end;
		hell:
		if ti <> tc then writeln;
	end;
end.

