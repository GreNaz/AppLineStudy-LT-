Action()
{
	lr_start_transaction("2_script_delete_reservation");

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");
	
	lr_start_transaction("open_site");
	
	web_reg_save_param("userSession",
		"LB/IC=name=\"userSession\" value=\"",
		"RB=\"/>",
		LAST);
	
	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("open_site", LR_AUTO);

	
	lr_think_time(5);
	
	lr_start_transaction("login");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	
	
	web_reg_find("Text/IC=User password was correct",
		LAST);
	

	web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t3.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={username}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=48", ENDITEM,
		"Name=login.y", "Value=15", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("login",LR_AUTO);

	
	
	lr_think_time(5);
	lr_start_transaction("Chek_ticket");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_find("Text= User wants the intineraries.",
		LAST);

	web_url("Itinerary Button",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary",
		"TargetFrame=body",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home",
		"Snapshot=t4.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("Chek_ticket",LR_AUTO);

	
	
	lr_think_time(5);
	lr_start_transaction("Cancel_reservation");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_find("Text=Flights List",
		LAST);

	web_submit_form("itinerary.pl", 
    "Snapshot=t100.inf", 
    ITEMDATA, 
    "Name=1", "Value=on", ENDITEM,  
    "Name=removeFlights.x", "Value=72", ENDITEM, 
    "Name=removeFlights.y", "Value=1", ENDITEM, 
    LAST);

	lr_end_transaction("Cancel_reservation",LR_AUTO);

	
	
	lr_think_time(5);
	lr_start_transaction("logout");

	web_add_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_find("Text=A Session ID has been created",
		LAST);

	
	web_url("welcome.pl",
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary",
		"Snapshot=t6.inf",
		"Mode=HTML",
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	lr_end_transaction("2_script_delete_reservation", LR_AUTO);
	
	return 0;
}