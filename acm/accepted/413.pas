program p413;
{
	@JUDGE_ID: 20044WC 413 PASCAL
}
var
	i,j,k,n,un,dn, ut,dt,st, a,b,s : longint;
function wrap(a,b:longint):double;
begin
	if b = 0 then wrap := 0 else wrap := a/b;
end;
begin
	while not eof do begin
		n := 1; s := 0; dt:=0;ut:=0;un:=0;dn:=0;st:=0;
		read(a);
		if a = 0 then break;
		while true do begin
			read(b);
			if b = 0 then break;
			inc(n);
			if b > a then begin
				inc(ut);
				if s = 2 then inc(dn);
				s := 1;
				inc(ut,st);
			end;
			if b < a then begin
				inc(dt);
				if s = 1 then inc(un);
				s := 2;
				inc(dt,st);
			end;
			if a = b then begin
				if s = 1 then inc(ut);
				if s = 2 then inc(dt);
				if s = 0 then inc(st);
			end else st := 0;
			a := b;
		end;
		readln;
		if s = 1 then begin inc(un); end;
		if s = 2 then begin inc(dn); end;
		writeln('Nr values = ', n, ':  ', wrap(ut,un):0:6, ' ', wrap(dt,dn):0:6);
	end;
end.
