#!/usr/bin/perl
use strict;
use warnings;

#    use open ':encoding(UTF-8)';
#    use open IO => ':encoding(UTF-8)';
# use encoding ':utf-8';

sub maybeset {
  my($n, $lesson, $teacher, $time, $room) = @_;
  #$Foo{$key} = $value unless $Foo{$key};
  print ("{\n\tlesson:",$lesson,",\n\tteacher:", $teacher,",\n\ttime:", $time,",\n\troom:", $room,"\n},")
}

my $file = $ARGV[0] or die "Need to get CSV file on the command line\n";
 
my $sum = 0;
open(my $data, "<:encoding(UTF-8)", $file) or die "Could not open '$file' $!\n";
 
while (my $line = <$data>) {
  chomp $line;
 
  my @fields = split "\t" , $line;
  maybeset ($fields[0],$fields[1],$fields[2],$fields[3],$fields[4])
#    print ("\"",$fields[2],"\"","\n");
#  $sum += $fields[2];
}
#print "$sum\n";




