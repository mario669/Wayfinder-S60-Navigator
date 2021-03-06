/*
  Copyright (c) 1999 - 2010, Vodafone Group Services Ltd
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
  * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
  * Neither the name of the Vodafone Group Services Ltd nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef NAVSERVERCOMENUMS_H
#define NAVSERVERCOMENUMS_H
namespace isab{
   namespace NavServerComEnums{
      /* These values are the ones used between the server and */
      /* the navigator and should not be confused with the */
      /* internal values or the values used between navigator */
      /* and PDA. */
      enum SearchType {
         SEARCH_TYPE_NORMAL = 0,
         SEARCH_TYPE_ROUTE,
      };

      /// Used in search requests to specify what kind of
      /// overviewmatches we want
      enum LocationSearchType{
         /// A municipal. 
         SEARCH_MUNICIPAL = 0x20,
         /// A built up area. 
         SEARCH_BUILT_UP_AREA = 0x40,
         /// A part of a city. 
         SEARCH_CITY_PART = 0x80,
         /// A zip code area. 
         SEARCH_ZIP_CODE = 0x100,
         /// A named zip area. 
         SEARCH_ZIP_AREA = 0x200,
      };

      /// Used in search requests to specify what kind of matches we want. 
      enum MatchSearchType{
         /// A street. 
         SEARCH_STREET = 0x01,
         /// A point of interest. 
         SEARCH_POI = 0x02,
         /// A category, expand to get categories or companies if leaf
         /// of category tree.
         SEARCH_CATEGORY = 0x04,
         /// A different type of item. Currently parks, lakes and some more. 
         SEARCH_MISC = 0x08,
      };

      /// Generate route for what?
     enum VehicleType {
         /// Passenger car.
         passengerCar           = 0x01,
         // Pedestrian.
         pedestrian             = 0x02,
         /// Emergency vehicle.
         emergencyVehicle       = 0x03,
         /// Taxi.
         taxi                   = 0x04,
         /// Public bus.
         publicBus              = 0x05,
         // Delivery truck.
         deliveryTruck          = 0x06,
         /// Transport truck.
         transportTruck         = 0x07,
         /// Car with more than 2 passengers.
         highOccupancyVehicle   = 0x08,
         /// Bicycle.
         bicycle                = 0x09,
         /// Public transportation.
         publicTransportation   = 0x0a,
         /// invalid, let the server decide.
         invalidVehicleType     = 0xff
      };

      /// Optimize route for what?
      enum RouteCostType {
         /// DISTANCE, optimize length of route.
         DISTANCE = 0,
         /// TIME, optimize time of route.
         TIME = 1,
         /**
          * TIME_WITH_DISTURBANCES, optimize time of route with 
          * disturbances.
          */
         TIME_WITH_DISTURBANCES = 2,
         ///Invalid, let the server decide.
         INAVLID = 0xff
      };

      /// How to handle toll roads
      enum RouteTollRoads {
         TollRoadsAllow = 0,
         TollRoadsDeny = 1,
      };
      /// How to handle highways
      enum RouteHighways {
         HighwaysAllow = 0,
         HighwaysDeny = 1,
      };

      ///How fleshed out route to send back.
      enum routeType { 
         ///Preferred by the GPS-less mode. Sends enough 
         ///information that an itinerary can be generated by 
         ///the client.
         slim = 1,
         ///Preferred by the GPS mode. Plenty of coordinates
         ///ensures good route following, distance and time to 
         ///goal calculation, and off track detection.
         full = 2,
      };

      /** Enumerates the reasons for a reroute. */
      enum RerouteReason {
         /** */
         unknown = 0,
         /** The route was truncated, the next piece is needed. */
         truncated_route     = 1,
         /** The user went off track and needs a new route.*/
         off_track           = 2,
         /** The route should be updated with new traffic info. */
         traffic_info_update = 3,
         /** The user requested a reroute. */
         user_request        = 4,
      };

      /// Used in search requests to specify different kinds of matching.
      enum MatchType {
         /// All letters must match but match may contain more letters. 
         ExactMatch = 0x00,
         /// Close match. 
         CloseMatch = 0x01,
         /// All letter must match and length of string miust be same. 
         FullMatch = 0x02,
         /// Match things that sounds alike. 
         PhoneticMatch = 0x03,
         /// Match strings allowing for a few misspellings. 
         EditdistanceMatch = 0x04,
      };

      /// Used in search requests to specify the type of word mathing to use.
      enum WordMatchType {
         Beginning = 0x00, /// Starts matching at begining of string. 
         Anywhere = 0x01,  /// String may match anywhere in match. 
      };

      /// Used in search requests to specify sort order of search matches. 
      enum SortTypes {
         /// The result will not be sorted. 
         NoSort = 0x00,
         /// Matches are sorted in alphabetical order. 
         AlfaSort = 0x01,
         /// Matches are sorted by confidence, attempting to place the
         /// most probable matches on top of the match list.
         ConfidenceSort = 0x02,
         /// Matches are sorted by their distance from the current coordinate. 
         DistanceSort = 0x04,
      };

      ///Language for replies from server.
      enum languageCode {
         ENGLISH          = 0, /// English
         SWEDISH          = 1, /// Swedish
         GERMAN           = 2, /// German
         DANISH           = 3, /// Danish
         FINNISH          = 4, /// Finnish
         NORWEGIAN        = 5, /// Norwegian
         ITALIAN          = 6, /// Italian 
         DUTCH            = 7, /// Dutch 
         SPANISH          = 8, /// Spanish 
         FRENCH           = 9, /// French 
         WELCH            = 10, /// Welsh 
         PORTUGUESE       = 11, /// Portuguese 
         CZECH            = 12, /// Czech 
         AMERICAN_ENGLISH = 13, /// American English
         HUNGARIAN        = 14, /// Hungarian
         GREEK            = 15, /// Greek
         POLISH           = 16, /// Polish
         SLOVAK           = 17, /// Slovak
         RUSSIAN          = 18, /// Russian
         SLOVENIAN        = 19, /// Slovenian
         TURKISH          = 20, /// Turkish
         ARABIC           = 21, /// Arabic
         SWISS_FRENCH       = 22,
         SWISS_GERMAN       = 23,
         ICELANDIC          = 24,
         BELGIAN_FLEMISH    = 25,
         AUSTRALIAN_ENGLISH = 26,
         BELGIAN_FRENCH     = 27,
         AUSTRIAN_GERMAN    = 28,
         NEW_ZEALAND_ENGLISH= 29,
         CHINESE_TAIWAN     = 30,
         CHINESE_HONG_KONG  = 31,
         CHINESE_PRC        = 32,
         JAPANESE           = 33,
         THAI               = 34,
         AFRIKAANS          = 35,
         ALBANIAN           = 36,
         AMHARIC            = 37,
         ARMENIAN           = 38,
         TAGALOG            = 39,
         BELARUSIAN         = 40,
         BENGALI            = 41,
         BULGARIAN          = 42,
         BURMESE            = 43,
         CATALAN            = 44,
         CROATIAN           = 45,
         CANADIAN_ENGLISH   = 46,
         SOUTH_AFRICAN_ENGLISH=47,
         ESTONIAN           = 48,
         FARSI              = 49,
         CANADIAN_FRENCH    = 50,
         GAELIC             = 51,
         GEORGIAN           = 52,
         GREEK_CYPRUS       = 53,
         GUJARATI           = 54,
         HEBREW             = 55,
         HINDI              = 56,
         INDONESIAN         = 57,
         IRISH              = 58,
         SWISS_ITALIAN      = 59,
         KANNADA            = 60,
         KAZAKH             = 61,
         KHMER              = 62,
         KOREAN             = 63,
         LAO                = 64,
         LATVIAN            = 65,
         LITHUANIAN         = 66,
         MACEDONIAN         = 67,
         MALAY              = 68,
         MALAYALAM          = 69,
         MARATHI            = 70,
         MOLDOVIAN          = 71,
         MONGOLIAN          = 72,
         NYNORSK            = 73,
         BRAZILIAN_PORTUGUESE=74,
         PUNJABI            = 75,
         ROMANIAN           = 76,
         SERBIAN            = 77,
         SINHALESE          = 78,
         SOMALI             = 79,
         LATIN_AMERICAN_SPANISH=80,
         SWAHILI            = 81,
         FINNISH_SWEDISH    = 82,
         TAMIL              = 83,
         TELUGU             = 84,
         TIBETAN            = 85,
         TIGRINYA           = 86,
         CYPRUS_TURKISH     = 87,
         TURKMEN            = 88,
         UKRAINIAN          = 89,
         URDU               = 90,
         VIETNAMESE         = 91,
         ZULU               = 92,
         SESOTHO            = 93,
         BASQUE             = 94,
         GALICIAN           = 95,
         ASIA_PACIFIC_ENGLISH=96,
         TAIWAN_ENGLISH     = 97,
         HONG_KONG_ENGLISH  = 98,
         CHINA_ENGLISH      = 99,
         JAPAN_ENGLISH      = 100,
         THAI_ENGLISH       = 101,
         ASIA_PACIFIC_MALAY = 102,
      };

      ///Common request status codes.
      enum ReplyStatus {
         /// All is well
         NAV_STATUS_OK                    = 0x00,
         /// Something is not that well
         NAV_STATUS_NOT_OK                = 0x01,
         /// Server internal timeout
         NAV_STATUS_REQUEST_TIMEOUT       = 0x02,
         /// Server didn't receive parameter request as first request
         /// in the session.
         NAV_STATUS_PARAM_REQ_NOT_FIRST   = 0x03,
         /// The server doesn't have map coverage of that area.
         NAV_STATUS_OUTSIDE_MAP           = 0x04,
         /// The server doesn't understand that protocol version
         NAV_STATUS_PROTOVER_NOT_SUPPORTED= 0x05,
         /// The user hasn't payed for that map.
         NAV_STATUS_OUTSIDE_ALLOWED_AREA  = 0x06,
         /// The user have no transactions left. 
         NAV_STATUS_NO_TRANSACTIONS_LEFT  = 0x07,
         // Unauthorized and other user has this phone's license
         NAV_STATUS_UNAUTH_OTHER_HAS_LICENSE=0x17,
         // The error is in the extened error code.
         NAV_STATUS_EXTENDED_ERROR = 0x18,
         /// Used to mask request specific status codes.
         NAV_STATUS_REQUEST_SPECIFIC_MASK = 0x80,
      };

#define REQUEST_SPECIFIC NAV_STATUS_REQUEST_SPECIFIC_MASK

      ///Request specific status messages for poll requests
      enum PollReplyStatus {
         POLL_SERVER_FINAL    = (0x02|REQUEST_SPECIFIC)
      };

      ///Request specific status messages for parameter requests
      enum ParamReplyStatus {
         ///User login is ok but subscription is expired. Tell user to
         ///pay on time every time.
         PARAM_REPLY_EXPIRED_USER     = (0x01|REQUEST_SPECIFIC),
         ///User login not ok, wrong password or invalid MSISDN and
         ///key pair.
         PARAM_REPLY_UNAUTHORIZED_USER=(0x02|REQUEST_SPECIFIC),
         ///Server moved, connect to it instead. Server list is in
         ///parametrers.
         PARAM_REPLY_REDIRECT         = (0x03|REQUEST_SPECIFIC),
         ///Client must upgrade! Send new Parameter Request with
         ///update parameter.
         PARAM_REPLY_UPDATE_NEEDED    = (0x04|REQUEST_SPECIFIC),
         ///Client says it is of a higher Wayfinder type than the
         ///server allows it to be.
         PARAM_REPLY_WF_TYPE_TOO_HIGH = (0x05|REQUEST_SPECIFIC),

         /// Other has your IMEI
         PARAM_REPLY_UNAUTH_OTHER_HAS_LICENSE = (0x17 | REQUEST_SPECIFIC),

         CHANGED_LICENSE_REPLY_OLD_LICENSE_NOT_IN_ACCOUNT       = 0xF1,
         CHANGED_LICENSE_REPLY_MANY_USERS_WITH_OLD_LICENSE      = 0xF2,
         CHANGED_LICENSE_REPLY_MANY_USERS_WITH_NEW_LICENSE      = 0xF3,
         CHANGED_LICENSE_REPLY_OLD_LICENSE_IN_OTHER_ACCOUNT     = 0xF4,

         UPGRADE_REPLY_MUST_CHOOSE_REGION                       = 0xFA,
      };

      ///Request specific status messages for route requests
      enum RouteReplyStatus {
         ///No route could be found to the destination. 
         ROUTE_REPLY_NO_ROUTE_FOUND        = (0x01|REQUEST_SPECIFIC),
         ///Route is too far to go for the vehicle used. Mostly used
         ///for pedestrian routes that are too long.
         ROUTE_REPLY_TOO_FAR_FOR_VEHICLE   = (0x02|REQUEST_SPECIFIC),
         ///Can not make out origin. 
         ROUTE_REPLY_PROBLEM_WITH_ORIGIN   = (0x03|REQUEST_SPECIFIC),
         ///Can not make out destination. 
         ROUTE_REPLY_PROBLEM_WITH_DEST     = (0x04|REQUEST_SPECIFIC),
         ///No auto destination and auto destination used as
         ///destination.
         ROUTE_REPLY_NO_AUTO_DEST          = (0x05|REQUEST_SPECIFIC),

         ROUTE_REPLY_NO_ORIGIN             = (0x06|REQUEST_SPECIFIC),
         ROUTE_REPLY_NO_DESTINATION        = (0x07|REQUEST_SPECIFIC),
         //This status may be returned by reroute requests. If it is
         //set, it means that the route has not changed and the client
         //should keep using the old route.
         ROUTE_REPLY_NO_ROUTE_CHANGE       = (0x08|REQUEST_SPECIFIC),
      };

      /** 32bit values specifing the type of binary data tranferred 
       * between the client and the server. Specified in the
       * 'Binary Transfers to the Navigator Server' document.
       * These enums comply with version 1.00 of that protocol. */
      enum BinaryTransferType {
         CrossingMapData      = 0x10, /// Crossing maps
         SyncFavoritesRequest = 0x11, /// Destination sync
         MapData              = 0x12, /// ???
         TopRegionListData    = 0x13, /// Top Region list
         CategoriesFile       = 0x15,
         LatestNewsFile       = 0x16,
         LogfileData          = 0x20, /// ???
      };

      ///Current status of server communication session. Used in
      ///statusreportmessages.
      enum ComStatus{
         /** Invalid. */
         invalid = 0,
         /** connecting to server. */
         connecting,
         /** connected to server. */
         connected,
         /** Sending data to server. */
         sendingData,
         /** Downloading data from server. */
         downloadingData,
         /** Session complete, shutting down connection. */
         done,
         /** Connection disrupted. */
         disconnectionError,
         /** unknown error caused the session to terminate.*/
         unknownError,
         /** No data has been received for a while. */
         connectionTimedOut,
         
         /// Sentinel value.
         numberOfStatuses,
      };

      enum TransactionType{
         transactions = 0,
         daysLeftTransactions = 2,
      };

#ifdef I_AM_DISPLAY_SERIAL_AND_IN_DIRE_NEED_OF_OUTDATED_ENUMS
      enum NavOutError {
         /* Phone call could not be made (busy, no answer etc) */
         nav_out_no_carrier                            = 0x0,
         /** Navigator server said "route not ok". */
         nav_out_not_ok_route_req                      = 0x1,
         /** Navigator server said "where am I not ok". */
         nav_out_not_ok_where_am_i_req                 = 0x2,
         /** Navigator server said "Search not ok". */
         nav_out_not_ok_search_req                     = 0x3,
         /** Server could not sync destinations. */
         nav_out_not_ok_sync_destinations_req          = 0x4,
         /** No phone connected. */
         nav_out_no_phone                              = 0x5,
         /** GPS quality too low. */
         nav_out_no_gps                                = 0x6,
         /** Other error. */
         nav_out_other_error                           = 0x7,
         /** Protocol error. */
         nav_pda_protocol_error                        = 0x8,
         /** The GPS positions are nowhere near the route, 
          * we can't even check the distance to the closest point... */
         nav_out_outside_route_area                    = 0x10,
         /** Unknown packet from PDA. */
         nav_out_unknown_packet                        = 0x11,
         /* Unexpected DATA_CHUNK packet from PDA. */
         nav_out_unexpected_data_chunk                 = 0x12,  

         /* Start tunnel setup failed. */
         nav_out_start_tunnel_fail                     = 0x13,
         
         /* Binary upload failed in some way. */
         nav_out_binary_upload_fail                    = 0x14,
         
         /*------- Phone status (may arrive at any time) */
         /**  No phone was connected to navigator, or phone went away. */
         STATUS_NO_PHONE               =  0x20,       // Error
         /**  Sim card not inserted in phone, or sim revoked. */
         STATUS_NO_SIM_CARD            =  0x21,       // Error
         /**  Weak signal to GSM network. */
         STATUS_PHONE_NO_NET           =  0x22,       // Error
         /*------- From phone when trying to connect */
         /**  Phone is not answering to commands */
         STATUS_PHONE_NOT_RESPONDING   =  0x23,       // Error
         /**  Phone is off hook (call in progress) */
         STATUS_PHONE_NOT_IDLE         =  0x24,       // Error
         /**  Server modem was busy. */
         STATUS_PHONE_BUSY_SIGNAL      =  0x25,       // Error
         /**  Server modem does not answer. */
         STATUS_PHONE_NO_ANSWER        =  0x26,       // Error
         /**  Phone is now available. */
         STATUS_PHONE_READY            =  0x27,
         /**  Dialling number. */
         STATUS_PHONE_DIALING          =  0x28,
         /**  Connecting to modem */
         STATUS_PHONE_CONNECTING       =  0x29,
         /**  Modem connection established. */
         STATUS_PHONE_CONNECTED        =  0x2a,
         /**  No data for a long time in online mode */
         STATUS_PHONE_NO_DATA          =  0x2b,       // Error
         /**  Disconnecting from remote modem. */
         STATUS_PHONE_DISCONNECTING    =  0x2c,
         /*------ From Navigator when trying to connect. */
         /**  Sending data to server */
         STATUS_NSC_SENDING_REQUEST    =  0x40,
         /**  Waiting for server answer. */
         STATUS_NSC_WAITING_FOR_ANSWER =  0x41,
         /**  Receving data from server. */
         STATUS_NSC_RECEIVING_ANSWER   =  0x42,
         /**  Call disconnected before we got all data in answer */
         STATUS_NSC_TRUNCATED_ANSWER   =  0x43,       // Error
         /**  Server timed out without answer. */
         STATUS_NSC_TIMEOUT_SERVER     =  0x44,       // Error
         /**  Phone timed out when sending. */
         STATUS_NSC_TIMEOUT_PHONE      =  0x45,       // Error
         /*------ From Navigator Server */
         /**  Username or password was wrong */
         STATUS_NS_AUTH_FAIL_LOGIN     = 0x60,        // Error
         /**  The server is not allowing logins. */
         STATUS_NS_AUTH_FAIL_FORBIDDEN = 0x61,        // Error
         /**  The account was closed by ISAB */
         STATUS_NS_AUTH_CLOSED_ACCOUNT = 0x62,        // Error
         /**  Server version is incompatible with client. */
         STATUS_NS_SERVER_VERSION_INCOMPATIBLE = 0x63,// Error
         /**  New version of client is available. */
         STATUS_NS_NEW_CLIENT_AVAILABLE = 0x64,
         /*------- The below errors should never reach the client. */
         nav_out_ok_sync_destinations_req              = 0x80,
         nav_out_ok_search_req                         = 0x81,
         nav_out_ok_where_am_i_req                     = 0x82,
         nav_out_ok_route_req                          = 0x83,
         nav_out_server_status_ok                      = 0x84,
         nav_out_server_status_not_ok                  = 0x85,
         nav_out_send_download_data                    = 0xfd,
         nav_out_message                               = 0xfe,
         nav_out_no_error                              = 0xff,
      };

      /** List of errors possible when doing server communication?  */
      enum NavErrorType {
         nav_error_type_no_error                       = 0x0,
         /* GPS quality does not admit request. */
         nav_error_type_no_gps                         = 0x1,
         /* Phone not connected. */
         nav_error_type_no_phone                       = 0x2,
         /* Server does not even pick up phone. */
         nav_error_type_no_server_answer               = 0x3,
         /* Server picks up phone but does not answer requests. */
         nav_error_type_no_server_connection           = 0x4,
         /* Route download was interrupted. */
         nav_error_type_route_download                 = 0x5,
         /* Route downloaded but format was wrong. */
         nav_error_type_route_format                   = 0x6,
         /* The navigator server could not route. */
         nav_error_type_routeing                       = 0x7,
         /* Search download was interrupted. */
         nav_error_type_search_download                = 0x8,
         /* Search downloaded but format was wrong. */
         nav_error_type_search_format                  = 0x9,
         /* The navigator server could not search. */
         nav_error_type_searching                      = 0xa,
         /* Where am I download interrupted. */
         nav_error_type_where_am_i_download            = 0xb,
         /* Where am I downloaded but format was wrong. */
         nav_error_type_where_am_i_format              = 0xc,
         /* The navigator server could not perform the Where am I action. */
         nav_error_type_where_am_i                     = 0xd,
         /* Reply from server was too large. */
         nav_error_type_reply_too_large                = 0xe,
         /* Call was disconnected. */
         nav_error_type_call_disconnected              = 0xf,

         /* The GPS positions are nowhere near the route, */
         /* we can't even check the distance to the closest point... */
         nav_error_type_outside_route_area             = 0x10,  

         /* Unknown packet from PDA. */
         nav_error_type_unknown_packet                 = 0x11,  

         /** Not really an error, canceled on request. */
         nav_error_type_canceled_on_request            = 0x12,

         /* Memory problems, no buffers, bugs etc. */
         nav_error_type_internal_nav_display_serial    = 0x80,
         nav_error_type_internal_nav_ctrl              = 0x81,
         nav_error_type_internal_nav_task              = 0x82,
         nav_error_type_internal_nav_server_com        = 0x83,
         nav_error_type_internal_plexor                = 0x84,
         nav_error_type_internal_driv_phone_eri520     = 0x85,


      };

      /** Enumeration of values in the status byte of server replies.*/
      enum ServerStatus {
         /** All is well with the world. */
         nav_server_status_ok         = 0x0,
         /** Something went wrong. */
         nav_server_status_not_ok     = 0x1,
         /** This was the final poll reply. No more data available.*/
         nav_server_status_poll_final = 0x2,
         /** Invalid. Used as placeholder when the error wasn't server 
             related.*/
         nav_server_invalid
      };
#endif
      /** The types of messages to send to and receive from the server.*/
      enum MessageType{
         /** Placeholder. */
         NAV_SERVER_INVALID               = 0x00,          

         /** Unused. */
         NAV_SERVER_PICK_ME_UP_REQ        = 0x01,
         /** Unused. */
         NAV_SERVER_PICK_ME_UP_REPLY      = 0x02,
         /** Unused. */
         NAV_SERVER_PICK_UP_REQ           = 0x03,
         /** Unused. */
         NAV_SERVER_PICK_UP_REPLY         = 0x04,

         /** Request for a route. Sent from Navigator to Server.*/
         NAV_SERVER_ROUTE_REQ             = 0x05,        
         /** A Reply for a route request. Sent from Server to Navigator. */
         NAV_SERVER_ROUTE_REPLY           = 0x06,
         /** A search request. Sent from Navigator to Server.*/
         NAV_SERVER_SEARCH_REQ            = 0x07,         
         /** A Reply for a search request. Sent from Server to Navigator. */
         NAV_SERVER_SEARCH_REPLY          = 0x08,
         /** Request for destination synchronization. Presently not
             used. Sent from Navigator to Server.*/
         NAV_SERVER_DEST_REQ              = 0x09,       
         /** A Reply to a destination synchronization
             request. Presently not used. Sent from Server to
             Navigator. */
         NAV_SERVER_DEST_REPLY            = 0x0a,        
         /** Request for a convertion of gps coordinates to a real
             world address. Sent from Navigator to Server.*/
         NAV_SERVER_GPS_ADDRESS_REQ       = 0x0b,
         /** A Reply to a request for an address. Sent from Server to
             Navigator. */
         NAV_SERVER_GPS_ADDRESS_REPLY     = 0x0c,
         /** Request for navigator to receive one gps position poer
             second from the Navigator. Sent from Navigator to
             Server.*/
         NAV_SERVER_GPS_POS_REQ           = 0x0d,         
         /** A Reply indicating whether the Server is ready to receive
             gps positions from the Navigator. Sent from Server to
             Navigator. */
         NAV_SERVER_GPS_POS_REPLY         = 0x0e,
         
         /** Request for more data from the server. Sent from the
             Navigator to the Server.*/
         NAV_SERVER_POLL_SERVER_REQ       = 0x10,
         /** Extra data from the Server. Sent from the Server to the
             Navigator. */
         NAV_SERVER_POLL_SERVER_REPLY     = 0x11,
         
         /** Request a map image from the server.*/
         NAV_SERVER_MAP_REQ               = 0x12,
         /** A map image from the server.*/
         NAV_SERVER_MAP_REPLY             = 0x13,

         /** Request Extra info about search items.*/
         NAV_SERVER_INFO_REQ              = 0x16,
         /** Contains Extra info about search items. */
         NAV_SERVER_INFO_REPLY            = 0x17,
         
         /** Asks server to send messages */
         NAV_SERVER_MESSAGE_REQ           = 0x18,
         /** Reply*/
         NAV_SERVER_MESSAGE_REPLY         = 0x19,
         
         /** Submit license key*/
         NAV_SERVER_UPGRADE_REQ           = 0x1a,
         /** Registration results. */
         NAV_SERVER_UPGRADE_REPLY         = 0x1b,
         /** Request Vector Map Chunk.*/
         NAV_SERVER_VECTOR_MAP_REQ        = 0x1c,
         /**Vector map chunk from server.*/
         NAV_SERVER_VECTOR_MAP_REPLY      = 0x1d,
         /** Request multiple Vector Maps from the server limited by
          * total size..*/
         NAV_SERVER_MULTI_VECTOR_MAP_REQ  = 0x1e,
         /** Multiple vector map reply. */
         NAV_SERVER_MULTI_VECTOR_MAP_REPLY= 0x1f,

         /** Parameters from the Navigator and the NavClient to the
             server. Sent from Navigator to server.*/
         NAV_SERVER_PARAMETER_REQ         = 0x20, 
         /** Parameters from the server to the Navigator. Sent from
             Server to Navigator. */
         NAV_SERVER_PARAMETER_REPLY       = 0x21,

         NAV_SERVER_CELL_REPORT           = 0x22,
         NAV_SERVER_CELL_CONFIRM          = 0x23,
         
         /** Request for GPS almanac. Sent from Navigator to server.*/
         NAV_SERVER_GPS_INIT_REQ          = 0x30,
         /** Reply with GPS almanac. Sent from Server to Navigator.*/
         NAV_SERVER_GPS_INIT_REPLY        = 0x31,

         /** Sending a binary block to the server. Sent from Navigator
             to server. */
         NAV_SERVER_BINARY_UPLOAD_REQ     = 0x32,
         /** Reply acknowledging a binary block. Sent from server to
             Navigator.*/
         NAV_SERVER_BINARY_UPLOAD_REPLY   = 0x33,

         /** Alarm information. Sent from Navigator to server. */
         NAV_SERVER_ALARM_REQ             = 0x40,
         /** Acknowledge of alarm info. Sent from server to navigator.*/
         NAV_SERVER_ALARM_REPLY           = 0x41,

         /** A NPG request */
         NAV_REQUEST                      = 0x50,
         /** A NPG reply */
         NAV_REPLY                        = 0x51,
      };

   }
}
#endif
