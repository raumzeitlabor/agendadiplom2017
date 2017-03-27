// Halterung für einen Micromotor
// Kann direkt auf die Platine montiert werden
// 
// Ingo M. Schaefer, Februar 2017

fn = 48;
hoehe = 6;
wandstaerke = 1.2;
motordurchmesser = 9;
sehne = (motordurchmesser+wandstaerke*2)/(sqrt(2));
platinenstaerke = 2;

difference()
{
	union()
	{
		// Der Ring um den Motor
		cylinder(h=hoehe, r=motordurchmesser/2+wandstaerke, center=true, $fn=fn);

		// Stabilisierung
		translate([0,-motordurchmesser/2-wandstaerke,0]) scale([1,2,1]) rotate([0,0,45]) cube([sehne, sehne, hoehe], center=true);

		// Sockel
		translate([0,-motordurchmesser-wandstaerke,0]) cube([motordurchmesser+wandstaerke*2,motordurchmesser,hoehe], center=true);

		// Ohren
		translate([+7.62/2, -motordurchmesser/2-0.075, -hoehe/2]) rotate([90,0,0]) cylinder(r=1.9, h=2.3, center=true, $fn=fn);
		translate([-7.62/2, -motordurchmesser/2-0.075, -hoehe/2]) rotate([90,0,0]) cylinder(r=1.9, h=2.3, center=true, $fn=fn);
	}

	// Innenteil (in der Form des Motors)
	difference() 
	{
		cylinder(h=hoehe+0.01, r=motordurchmesser/2, center=true, $fn=fn);
		translate([0,5+7/2,0]) cube([10,10,hoehe+1], center=true);
		translate([0,-5-7/2,0]) cube([10,10,hoehe+1], center=true);
	}

	// Ohrlöcher
	translate([+7.62/2, -motordurchmesser/2-0.075, -hoehe/2-0.65]) rotate([90,0,0]) cylinder(r=0.65, h=3, center=true, $fn=fn);
	translate([-7.62/2, -motordurchmesser/2-0.075, -hoehe/2-0.65]) rotate([90,0,0]) cylinder(r=0.65, h=3, center=true, $fn=fn);


	// Schlitz
	translate([0,5,0]) cube([3,5,hoehe+1], center=true); 

	// Abflachung oben
	translate([0,motordurchmesser/2+wandstaerke,0]) cube([10,2,hoehe+1], center=true); 

	// Schräge
	translate([0,-15.1,0]) rotate([35,0,0]) cube([motordurchmesser+wandstaerke*2+1,12,hoehe+20], center=true);

	// Abflachung unten
	translate([0,-11,0]) cube([12,5,hoehe+1], center=true); 

}



