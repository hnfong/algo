var
   min,max,t,i,j,k,n,v,best : integer;
   tot,s                    : array [1..40] of integer;
procedure srch;
var
   i : integer;
begin
	write('.');
   if k = n+1 then begin
      writeln(best);
      halt(0);
   end;
   for i := 1 to max do
	     if tot[i] + s[k] <= v then begin
            inc(tot[i],s[k]);
            inc(k);
            srch;
            dec(k);
            dec(tot[i],s[k]);
         end;
         if max + 1 <= best then begin
            inc(max);
            tot[max] := s[k];
            inc(k);
            srch;
            dec(k);
            dec(max);
         end;
end;
begin
   readln(n,v);
   for i := 1 to n do read(s[i]);
   for i := 1 to n-1 do
      for j := n downto i+1 do if s[j] > s[j-1] then begin
         t := s[j];
         s[j] := s[j-1];
         s[j-1] := t;
      end;
   {best := n;}
   for i := 1 to n do inc(min,s[i]);
   min := (min+v-1) div v;
   for best := min to n do begin
      max := 0;
      k := 1;
      srch;
   end;
end.
