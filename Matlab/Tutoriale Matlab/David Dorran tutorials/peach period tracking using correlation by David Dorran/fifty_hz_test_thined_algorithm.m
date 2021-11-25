clc
close all
clear all

x = [704227909	  714909096	  714795555	  704821021	  688126021	  667847726	  648021949	  632848065	  624841513	  625296911	  634129347	  649055559	  668024533	  688508292	  705937109	  715531019	  715566895	  706654788	  691052550	  672839182	  656579879	  644838705	  639042948	  640205050	  647519121	  659486717	  675628538	  694364661	  711009205	  720565429	  720166734	  709471363	  691153837	  670479282	  653169240	  643028432	  641284190	  647189012	  657970314	  671517287	  687643714	  704855665	  718576044	  725893623	  726087646	  716923880	  699330668	  679114545	  661467098	  649448770	  646269562	  652544725	  664961795	  679690811	  695248841	  709681596	  719245409	  723228492	  722805098	  716131550	  702542592	  686076112	  671533958	  661904562	  660271365	  667728622	  681069864	  696405020	  711390813	  723302124	  729509539	  729358640	  723111612	  711238571	  694634956	  676068315	  661451699	  656001943	  660853292	  674348996	  693302924	  713181733	  729226484	  738924046	  742085899	  739268185	  732496598	  722718806	  707799117	  688612665	  671746845	  662675859	  662893603	  672483850	  690282972	  711283660	  728695619	  737808822	  739315002	  736337903	  730549881	  722373237	  711910283	  699980974	  689141078	  682026696	  679995865	  684963880	  698188459	  715317953	  729868368	  739826586	  744843503	  742849604	  734842208	  724520173	  713281857	  701690316	  693371347	  690596874	  692213219	  697349364	  705147331	  712688865	  718463336	  724518572	  731851163	  738445303	  743198764	  745548785	  743087575	  734278552	  722089204	  711534630	  703953388	  698246231	  694908857	  694359252	  696331449	  702074832	  712643478	  727694061	  745364470	  760659207	  767217764	  762775729	  750648205	  734280483	  716214688	  700758333	  691176522	  686711448	  685057724	  686556077	  694265156	  709922980	  731010225	  753883222	  774900836	  788045581	  787036476	  771731801	  747582358	  720606391	  696403315	  678771982	  668992695	  667611816	  674728018	  688961792	  708073175	  730387716	  752979900	  770181407	  777401013	  774465246	  763565197	  747458351	  729247860	  711808020	  698267282	  690664961	  688942397	  692907657	  701553176	  712596958	  724080429	  732643198	  735134061	  732507995	  726960474	  719767895	  713047534	  709961732	  710964926	  713765007	  716989097	  720266611	  722661566	  723721233	];

y = [0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 6125897	 30850603	 55344044	 80034275	 104544960	 129192312	 153826421	 178363897	 203013031	 227504958	 252049251	 276750546	 301251774	 325669241	 350414340	 374924292	 399542698	 424174756	 448797809	 471088936	 487446887	 508792024	 525363698	 533120756	 561024935	 560320883	 584008337	 586750655	 601695805	 616994523	 616099994	 648975358	 611107952	 689655050	 614127218	 704227909	 656579879	 687643714	 702542592	 693302924	 730549881	 692213219	 712643478	  ];

thin_test = [0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 14409653	 31284486	 47945174	 64358392	 80504479	 96284694	 111705177	 126704474	 141758801	 156365096	 170446576	 183905440	 196772319	 209011223	 220550894	 231467623	 241600944	 250560241	 258010394	 264666271	 270572519	 275663293	 279874179	 283269748	 285826546	 287761122	 289046255	 289913556	 289985209	 289179523	 287517107	 284974336	 281549636	 277316657	 272226059	 265958163	 258904861	 251145724	 242724771	 233651396	 223974131	 213721151	 202925480	 191615839	 179836870	 167625613	 155025731	 142063014	 128780589	 115243722	 101456299	 87494429	 73368477	 59135667	 44839177	 30553586	 16816714	 3160237	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 0	 ];

aimed_test = [  283269748	  283417068	  283562976	  283712642	  283856897	  283989779	  284127877	  284261907	  284395543	  284527092	  284661423	  284791569	  284924544	  285054504	  285176156	  285291032	  285407247	  285515455	  285617459	  285723494	  285826546	  285930195	  286038659	  286145442	  286249433	  286353643	  286453242	  286546416	  286631333	  286712825	  286798811	  286889403	  286985564	  287088865	  287188919	  287292859	  287401747	  287499173	  287585720	  287670433	  287761122	  287838006	  287912860	  287987931	  288062977	  288141084	  288222302	  288300087	  288376378	  288449825	  288519812	  288583174	  288636789	  288688239	  288737845	  288784664	  288836971	  288888136	  288939690	  288995101	  289046255	  289101199	  289143996	  289184880	  289227221	  289273774	  289322692	  289374313	  289423167	  289473665	  289526286	  289576923	  289624436	  289670610	  289716995	  289759145	  289797001	  289833504	  289864063	  289890133	  289913556	  289934699	  289956161	  289977155	  289994671	  290013503	  290029350	  290046031	  290057006	  290063075	  290070229	  290074217	  290068969	  290062147	  290056710	  290044125	  290035932	  290025434	  290011416	  290000588	  289985209	  289964938	  289948920	  289930606	  289905527	  289876311	  289849254	  289815240	  289779690	  289741320	  289700177	  289656556	  289615654	  289569483	  289518399	  289466657	  289414290	  289358430	  289301487	  289241508	  289179523	  289119506	  289055560	  288988428	  288917770	  288849495	  288776659	  288702346	  288624181	  288540478	  288457575	  288374286	  288290765	  288203671	  288111415	  288023164	  287928435	  287828235	  287726123	  287621591	  287517107	  287414513	  287307524	  287193796	  287074542	  286953156	  286830476	  286705908	  286582378	  286456111	  286328755	  286205532	  286078166	  285945938	  285812923	  285682266	  285549718	  285409458	  285264311	  285123137	  284974336	  284820764	  284665342	  284507508	  284348691	  284192530	  284027155	  283858485	  283690025	  283518330	  283344430	  283169270	  282997781	  282822157	  282644686	  282469510	  282291725	  282110436	  281924851	  281740304	  281549636	  281354417	  281157127	  280957911	  280754630	  280552536	  280351582	  280150979	  279944987	  279738243	  279531083	  279314546	  279095827	  278875062	  278650655	  278432520	  278215616	  277995220	  277771663	  277544307  277316657];

locked_samples = [ -281	  -281	  -282	  -281	  -281	  -281	  -281	  -281	  -286	  -286	  -288	  -286	  -287	  -285	  -285	  -283	  -285	  -287	  -289	  -287	  -287	  -290	  -291	  -290	  -290	  -289	  -288	  -289	  -290	  -291	  -292	  -293	  -295	  -295	  -294	  -294	  -294	  -292	  -292	  -291	  -292	  -293	  -296	  -297	  -298	  -300	  -299	  -300	  -300	  -299	  -298	  -300	  -298	  -299	  -300	  -300	  -301	  -302	  -302	  -304	  -304	  -303	  -301	  -301	  -300	  -300	  -304	  -304	  -305	  -306	  -305	  -306	  -306	  -304	  -305	  -305	  -306	  -306	  -307	  -305	  -306	  -305	  -307	  -310	  -311	  -313	  -312	  -310	  -307	  -309	  -309	  -309	  -308	  -310	  -312	  -314	  -316	  -314	  -314	  -313	  -313	  -314	  -316	  -316	  -317	  -317	  -317	  -313	  -311	  -310	  -312	  -311	  -309	  -312	  -315	  -316	  -317	  -317	  -318	  -316	  -315	  -315	  -316	  -316	  -317	  -316	  -318	  -317	  -318	  -319	  -316	  -315	  -317	  -316	  -317	  -320	  -322	  -321	  -321	  -322	  -323	  -324	  -322	  -319	  -321	  -321	  -319	  -321	  -321	  -320	  -321	  -322	  -322	  -321	  -320	  -318	  -320	  -321	  -326	  -325	  -323	  -325	  -327	  -324	  -324	  -323	  -324	  -324	  -325	  -325	  -324	  -325	  -325	  -326	  -326	  -325	  -323	  -323	  -321	  -323	  -324	  -322	  -324	  -323	  -322	  -322	  -323	  -323	  -325	  -327	  -327	  -326	  -326	  -327	  -327	  -329	  -330	  -329	  -329	  -327	  -325	  -325	  -325	  -326	  -328	  -328	  -327	  -328	  -328	  -327	  -325	  -325	  -325	  -326	  -326	  -325	  -324	  -324	  -324	  -323	  -323	  -324	  -325	  -325	  -325	  -325	  -324	  -325	  -325	  -324	  -323	  -325	  -325	  -324	  -324	  -325	  -325	  -325	  -323	  -324	  -323	  -323	  -324	  -322	  -322	  -321	  -325	  -326	  -325	  -321	  -321	  -322	  -321	  -320	  -323	  -324	  -324	  -322	  -323	  -323	  -323	  -324	  -322	  -320	  -321	  -321	  -322	  -323	  -321	  -323	  -324	  -323	  -321	  -322	  -324	  -323	  -323	  -322	  -322	  -321	  -319	  -321	  -319	  -318	  -319	  -319	  -320	  -321	  -320	  -318	  -316	  -317	  -316	  -314	  -314	  -314	  -314	  -315	  -317	  -315	  -314	  -313	  -315	  -315	  -316	  -316	  -315	  -314	  -313	  -313	  -312	  -312	  -313	  -311	  -307	  -311	  -311	  -311	  -312	  -310	  -311	  -311	  -309	  -307	  -307	  -306	  -307	  -305	  -305	  -306	  -306	  -308	  -308	  -306	  -306	  -305	  -304	  -303	  -304	  -305	  -304	  -304	  -305	  -305	  -304	  -303	  -299	  -298	  -299	  -300	  -298	  -300	  -299	  -300	  -300	  -297	  -296	  -297	  -296	  -295	  -296	  -296	  -296	  -296	  -295	  -294	  -292	  -292	  -293	  -294	  -291	  -291	  -290	  -290	  -292	  -294	  -295	  -292	  -294	  -293	  -290	  -288	  -287	  -287	  -287	  -286	  -286	  -286	  -286	  -286	  -287	  -286	  -285	  -284	  -286	  -286	  -284	  -283	  -281	  -281   -279	  -278	  -280	  -281	  -278	  -280	  -281	  -279	  -279	  -279	  -279	  -277	  -277	  -277	  -277	  -276	  -274	  -276	  -272	  -272	  -274	  -273	  -273	  -273	  -271	  -272	  -270	  -267	  -265	  -265	  -264	  -265	  -266	  -265	  -265	  -268	  -265	  -266	  -265	  -263	  -260	  -260	  -261	  -261	  -264	  -263	  -262	  -260	  -259	  -256	  -257	  -254	  -253	  -254	  -254	  -254	  -255	  -255	  -256	  -255	  -253	  -253	  -252	  -248	  -246	  -248	  -248	  -246	  -246	  -244	  -246	  -245	  -243	  -242	  -243	  -243	  -243	  -244	  -245	  -244	  -242	  -241	  -238	  -237	  -238	  -239	  -237	  -235	  -235	  -235	  -236	  -235	  -234	  -230	  -229	  -229	  -228	  -231	  -230	  -228	  -227	  -228	  -225	  -223	  -226	  -225	  -226	  -227	  -225	  -222	  -224	  -220	  -221	  -219	  -219	  -218	  -219	  -218	  -217	  -216	  -214	  -213	  -215	  -214	  -214	  -214	  -211	  -210	  -209	  -207	  -206	  -207	  -208	  -208	  -207	  -205	  -205	  -205	  -203	  -201	  -206	  -201	  -188	  -194	  -201	  -200	  -198	  -195	  -196	  -197	  -199	  -195	  -197	  -195	  -190	  -190	  -190	  -190	  -191	  -190	  -190	  -191	  -190	  -187	  -186	  -186	  -187	  -187	  -186	  -184	  -181	  -181	  -179	  -180	  -179	  -180	  -179	  -177	  -174	  -173	  -174	  -173	  -173	  -175	  -174	  -174	  -172	  -172	  -168	  -167	  -166	  -165	  -165	  -163	  -164	  -163	  -164	  -162	  -161	  -159	  -159	  -159	  -158	  -159	  -156	  -155	  -155	  -154	  -153	  -153	  -153	  -153	  -152	  -150	  -150	  -148	  -147	  -147	  -148	  -147	  -148	  -147	  -144	  -142	  -143	  -139	  -141	  -141	  -142	  -141	  -141	  -137	  -135	  -133	  -130	  -129	  -130	  -129	  -131	  -130	  -129	  -127	  -128	  -126	  -126	  -125	  -125	  -125	  -126	  -126	  -123	  -120	  -118	  -116	  -115	  -114	  -113	  -112	  -113	  -113	  -114	  -113	  -111	  -108	  -105	  -106	  -108	  -111	  -110	  -110	  -108	  -104	  -104	  -101	  -100	  -99	  -99	  -101	  -101	  -98	  -98	  -97	  -93	  -92	  -90	  -90	  -89	  -93	  -91	  -92	  -89	  -87	  -87	  -86	  -82	  -79	  -82	  -82	  -82	  -82	  -82	  -81	  -81	  -79	  -77	  -76	  -72	  -71	  -71	  -69	  -69	  -69	  -67	  -67	  -66	  -66	  -66	  -67	  -65	  -65	  -65	  -63	  -63	  -61	  -58	  -56	  -55	  -53	  -54	  -55	  -55	  -55	  -55	  -53	  -51	  -51	  -49	  -47	  -48	  -45	  -44	  -44	  -44	  -42	  -45	  -42	  -43	  -41	  -39	  -39	  -37	  -35	  -34	  -33	  -33	  -34	  -32	  -32	  -30	  -30	  -29	  -28	  -28	  -26	  -21	  -26	  -26	  -26	  -23	  -22	  -21	  -20	  -20	  -20	  -21	  -20	  -20	  -17	  -15	  -14	  -12	  -10	  -8	  -5	  -5	  -8	  -10	  -8	  -7	  -4	  -5	  -4	  -4	  -2	  0	  1	  2	  5	  4	  5	  5	  4	  3	  5	  8	  9	  12	  10	  14	  16	  16	  16	  14	  16	  17	  19	  18	  21	  23	  25	  26	  26	  26	  26	  25	  25	  26	  29	  31	  33	  34	  34	  34	  32	  34	  35	  35	  36	  37	  39	  40	  41	  42	  44	  42	  45	  46	  46	  46	  45	  48	  50	  52	  52	  52	  52	  56	  57	  58	  58	  59	  59	  61	  60	  62	  65	  64	  63	  65	  67	  66	  66	  66	  65	  65	  68	  69	  70	  73	  73	  75	  77	  77	  79	  79	  79	  79	  81	  82	  83	  85	  83	  84	  84	  83	  87	  92	  91	  91	  93   91	  92	  93	  93	  93	  93	  95	  95	  96	  99	  100	  101	  101	  102	  102	  101	  103	  103	  104	  107	  109	  111	  113	  111	  111	  114	  111	  110	  112	  113	  114	  116	  118	  118	  121	  121	  121	  121	  123	  122	  123	  122	  121	  126	  127	  127	  125	  126	  127	  129	  129	  131	  133	  133	  135	  136	  135	  127	  139	  139	  138	  140	  141	  142	  143	  143	  144	  143	  145	  144	  145	  145	  148	  150	  153	  153	  154	  155	  152	  151	  150	  150	  153	  155	  157	  159	  159	  161	  163	  162	  160	  162	  164	  165	  163	  167	  166	  165	  165	  167	  168	  169	  168	  172	  174	  173	  175	  175	  176	  178	  177	  176	  176	  177	  179	  182	  185	  182	  182	  184	  183	  185	  187	  188	  189	  188	  186	  189	  187	  187	  186	  189	  189	  194	  196	  195	  197	  195	  195	  195	  196	  198	  200	  200	  202	  204	  202	  201	  201	  202	  202	  205	  205	  203	  204	  205	  206	  207	  207	  208	  208	  210	  210	  208	  210	  211	  215	  217	  215	  215	  214	  216	  217	  217	  217	  219	  220	  221	  224	  225	  223	  223	  222	  223	  226	  226	  224	  225	  228	  226	  227	  229	  226	  228	  229	  229	  230	  231	  231	  233   232	  233	  234	  233	  234	  236	  238	  237	  237	  239	  237	  236	  235	  238	  240	  241	  241	  246	  247	  243	  243	  243	  245	  247	  253	  250	  252	  250	  250	  249	  252	  252	  251	  254	  255	  255	  257	  255	  255	  257	  259	  261	  262	  263	  261	  259	  259	  259	  257	  246	  259	  260	  262	  265	  264	  262	  264	  260	  261	  262	  264	  266	  268	  267	  265	  268	  267	  264	  268	  269	  268	  271	  273	  274	  273	  271	  271	  271	  273	  274	  275	  276	  275	  277	  276	  275	  275	  275	  274	  276	  279	  279	  282	  284	  282	  281	  280	  279	  280	  281	  280	  280	  281	  284	  287	  287	  289	  285	  284	  284	  285	  287	  289	  290	  288	  287	  286	  289	  287	  289	  289	  288	  289	  289	  291	  291	  292	  295	  295	  294	  293	  294	  295	  295	  295	  295	  293	  294	  296	  295	  295	  296	  299	  300	  299	  297	  298	  299	  298	  298	  299	  301	  303	  303	  302	  299	  300	  300	  302	  301	  300	  301	  300	  299	  301	  303	  303	  305	  306	  305	  305	  305	  306	  307	  308	  307	  309	  305	  303	  303	  304	  307	  310	  309	  309	  309	  310	  315	  312	  309	  309	  309	  309	  311	  315	  313	  309	  306	  307	  305	  307	  305	  309	  313	  315	  314	  316	  315	  317	  317	  316	  313	  311	  310	  312	  314	  315	  315	  315	  314	  311	  312	  316	  310	  312	  313	  315	  317	  319	  319	  318	  317	  316	  319	  319	  317	  319	  322	  318	  320	  323	  318	  317	  316	  317	  314	  315	  316	  316	  317	  317	  318	  313	  313	  314	  312	  314	  314	  312	  313	  313	  319	  319	  319	  319	  321	  319	  319	  317	  319	  320	  319	  318	  319	  317	  320	  317	  316	  317	  317	  319	  319	  318	  318	  318	  318	  318	  319	  318	  318	  315	  317	  317	  317	  317	  316	  318	  319	  318	  317	  316	  314	  318	  319	  316	  317	  318	  315	  314	  312	  313	  318	  315	  313	  317	  312	  311	  312	  315	  313	  314	  315	  313	  311	  311	  310	  312	  311	  313	  315	  314	  314	  314	  312	  310	  311	  308	  312	  314	  311	  316	  316	  314	  315	  313	  314	  314	  315	  312	  312	  314	  311	  311	  311	  313	  312	  313	  311	  309	  309	  307	  306	  307	  306	  306	  305	  305	  307	  308	  309	  310	  307	  307	  307	  305	  303	  305	  301	  305	  307	  307	  309	  302	  302	  301	  300	  302	  303	  303	  306	  306	  303	  300	  301	  301	  299	  298	  296	  296	  296   295	  297	  298	  295	  296	  296	  294	  296	  298	  296	  298	  297	  298	  300	  300	  298	  299	  295	  293	  293	  290	  289	  286	  288	  290	  292	  291	  291	  291	  290	  290	  288	  289	  289	  290	  290	  290	  289	  289	  286	  286	  286	  284	  284	  283	  282	  281	  281	  280	  283	  283	  283	  284	  285	  284	  280	  279	  277	  277	  276	  275	  277	  277	  279	  278	  279	  278	  280	  275	  275	  271	  271	  271	  270	  271	  269	  270	  272	  273	  271	  271	  270	  268	  265	  265	  266	  267	  266	  267	  268	  266	  266	  266	  267	  268	  266	  265	  263	  261	  260	  259	  258	  257	  257	  258	  257	  258	  258	  257	  255	  253	  253	  254	  250	  251	  251	  253	  251	  254	  254	  254	  253	  251	  251	  248	  247	  247	  248	  247	  247	  247	  245	  242	  242	  243	  242	  243	  243	  241	  242	  241	  239	  239	  238	  235	  236	  236	  235	  236	  237	  234	  234	  235	  231	  232	  231	  230	  231	  230	  229	  229	  227	  226	  225	  226	  225	  225	  223	  223	  225	  223	  219	  219	  219	  217	  217	  219	  219	  221	  217	  214	  215	  215	  215	  213	  213	  210	  210	  211	  209	  207	  207	  206	  206	  206	  206	  206	  203	  201	  203	  201	  201	  202	  201	  199	  198	  197	  195	  194	  193	  193	  194	  194	  191	  191	  190	  189	  191	  190	  189	  190	  190	  187	  184	  183	  184	  185	  186	  185	  185	  183	  181	  181	  179	  177	  178	  181	  176	  175	  174	  171	  172	  172	  172	  174	  174	  169	  167	  167	  165	  167	  171	  168	  168	  164	  163	  164	  161	  160	  162	  161	  159	  158	  153	  156	  156	  155	  153	  154	  150	  154	  150	  150	  149	  151	  150	  150	  152	  150	  147	  145	  145	  143	  144	  143	  141	  142	  141	  138	  139	  138	  135	  134	  137	  140	  134	  134	  132	  132	  133	  129	  131	  129	  130	  131	  131	  127	  126	  126	  125	  125	  121	  121	  124	  121	  118	  116	  116	  112	  113	  115	  112	  114	  114	  112	  110	  108	  108	  108	  106	  104	  106	  105	  103	  102	  101	  99	  96	  97	  95	  98	  99	  99	  99	  97	  93	  93	  91	  89	  92	  91	  91	  92	  92	  87	  85	  85	  82	  82	  79	  79	  78	  79	  80	  77	  76	  76	  76	  74	  73	  76	  77	  75	  75	  71	  69	  66	  67	  65	  65	  64	  61	  64	  63	  63	  62	  61	  59	  59	  58	  53	  53	  53	  53	  54	  54	  53	  51	  47	  47   46	  45	  43	  39	  39	  41	  41	  41	  39	  38	  37	  36	  37	  38	  37	  38	  35	  36	  34	  33	  31	  31	  29	  28	  29	  28	  27	  28	  26	  23	  25	  24	  20	  18	  17	  16	  16	  14	  14	  14	  14	  14	  14	  12	  10	  9	  8	  6	  5	  5	  5	  5	  8	  6	  7	  4	  1	  -2	  -4	  -6	  -6	  -7	  -9	  -6	  -6	  -8	  -8	  -8	  -9	  -13	  -16	  -15	  -15	  -14	  -16	  -15	  -14	  -17	  -18	  -18	  -22	  -22	  -24	  -26	  -27	  -25	  -27	  -25	  -26	  -27	  -28	  -30	  -33	  -35	  -35	  -37	  -38	  -39	  -38	  -38	  -36	  -37	  -36	  -40	  -40	  -41	  -43	  -45	  -45	  -47	  -49	  -49	  -49	  -49	  -50	  -53	  -55	  -57	  -55	  -57	  -56	  -54	  -54	  -55	  -57	  -60	  -60	  -61	  -63	  -62	  -63	  -65	  -66	  -65	  -65	  -66	  -68	  -71	  -71	  -70	  -72	  -68	  -68	  -70	  -71	  -73	  -75	  -76	  -76	  -81	  -82	  -82	  -84	  -82	  -81	  -84	  -84	  -83	  -85	  -84	  -87	  -90	  -91	  -93	  -91	  -89	  -92	  -93	  -95	  -94	  -93	  -95	  -97	  -101	  -101	  -101	  -103	  -103	  -104	  -103	  -103	  -103	  -105	  -106	  -104	  -107	  -107	  -109	  -111	  -112	  -113	  -113	  -112	  -113	  -115	  -116	  -118	  -122	  -124	  -124	  -125	  -124	  -123	  -123	  -122	  -123	  -129	  -128	  -126	  -127	  -127	  -128	  -129	  -126	  -129	  -131	  -132	  -133	  -135	  -138	  -139	  -138	  -136	  -139	  -138	  -141	  -142	  -142	  -142	  -145	  -149	  -148	  -147	  -148	  -149	  -149	  -148	  -149	  -150	  -153	  -152	  -154	  -155	  -155	  -152	  -155	  -154	  -157	  -160	  -160	  -165	  -167	  -166	  -164	  -164	  -163	  -163	  -165	  -165	  -167	  -169	  -168	  -168	  -168	  -168	  -170	  -172	  -173	  -173	  -176	  -176	  -177	  -179	  -181	  -179	  -179	  -178	  -179	  -182	  -182	  -182	  -181	  -183	  -186	  -186	  -185	  -186	  -187	  -186	  -189	  -187	  -187	  -186	  -189	  -192	  -192	  -195	  -194	  -196	  -198	  -197	  -197	  -197	  -198	  -200	  -201	  -202	  -203	  -204	  -203	  -201	  -203	  -200	  -203	  -205	  -204	  -206	  -206	  -206	  -207	  -206	  -206	  -207	  -210	  -212	  -213	  -211	  -211	  -210	  -212	  -212	  -215	  -217	  -218	  -219	  -218	  -217	  -217	  -217	  -219	  -221	  -224	  -225	  -225	  -225	  -224	  -224	  -226	  -228	  -230	  -230	  -229	  -227	  -230	  -231	  -230	  -233	  -234	  -236	  -236	  -235	  -235	  -234	  -234	  -235	  -237	  -239	  -241	  -245	  -241	  -239	  -239	  -239	  -240	  -240	  -242	  -245	  -246	  -248	  -246	  -247	  -248	  -247	  -246	  -247	  -248	  -251	  -249	  -246	  -251	  -252	  -250	  -250	  -250	  -253	  -256	  -255	  -256	  -255	  -255   -253	  -261	  -258	  -260	  -259	  -260	  -261	  -259	  -260	  -259	  -261	  -262	  -264	  -264	  -264	  -265	  -266	  -265	  -266	  -267	  -269	  -270	  -269	  -270	  -268	  -269	  -266	  -267	  -269	  -268	  -269	  -271	  -272	  -269	  -270	  -269	  -271	  -271	  -272	  -275	  -279	  -280	  -278	  -279	  -278	  -277	  -279	  -277	  -279	  -280	  -282	  -283	  -284	  -284	  -281	  -281	  -283	  -286	  -285	  -285	  -287	  -287	  -286	  -284	  -283	  -283	  -283	  -286	  -286	  -287	  -288	  -288	  -290	  -291	  -290	  -290	  -291	  -291	  -291	  -292	  -289	  -293	  -295	  -297	  -296	  -298	  -296	  -293	  -294	  -295	  -296	  -297	  -295	  -296	  -296	  -295	  -297	  -299	  -298	  -300	  -299	  -299	  -297	  -297	  -297	  -299	  -299	  -303	  -303	  -305	  -304	  -303	  -303	  -302	  -306	  -306	  -305	  -305	  -305	  -303	  -303	  -304	  -307	  -308	  -310	  -309	  -307	  -309	  -309	  -309	  -308	  -307	  -309	  -309	  -307	  -307	  -308	  -307	  -309	  -312	  -314	  -311	  -313	  -312	  -313	  -312	  -310	  -310	  -311	  -312	  -312	  -311	  -310	  -311	  -312	  -315	  -317	  -318	  -317	  -316	  -316	  -317	  -316	  -316	  -316	  -315	  -315	  -316	  -317	  -315	  -314	  -314	  -314	  -314	  -318	  -321	  -321	  -323	  -322	  -319	  -319	  -319	  -316	  -316	  -317	  -317	  -318	  -319	  -317	  -318	  -315	  -316	  -319	  -330	  -319	  -319	  -319	  -320	  -321	  -321	  -323	  -322	  -324	  -322	  -323	  -323	  -322	  -321	  -321	  -322	  -322	  -323	  -323	  -324	  -323	  -322	  -322	  -321	  -320	  -320	  -321	  -319	  -320	  -321	  -323	  -323	  -323	  -321	  -319	  -318	  -318	  -316	  -319	  -323	  -324	  -324	  -325	  -325	  -327	  -328	  -327	  -327	  -323	  -325	  -326	  -325	  -326	  -324	  -321	  -322	  -325	  -324	  -322	  -324	  -323	  -322	  -323	  -323	  -324	  -323	  -324	  -321	  -320	  -321	  -321	  -323	  -323	  -321	  -323	  -323	  -323	  -323	  -322	  -322	  -322	  -323	  -322	  -322	  -321	  -322	  -325	  -324	  -322	  -324	  -321	  -321	  -321	  -321	  -321	  -321	  -319	  -318	  -318	  -320	  -322	  -322	  -319	  -319	  -319	  -317	  -317	  -319	  -320	  -321	  -320	  -319	  -319	  -320	  -321	  -321	  -323	  -321	  -321	  -321	  -320	  -317	  -320	  -322	  -320	  -318	  -316	  -317	  -319	  -317	  -319	  -321	  -321	  -318	  -318	  -316	  -315	  -313	  -312	  -312	  -312	  -312	  -311	  -313	  -313	  -312	  -312	  -311	  -310	  -309	  -309	  -310	  -310	  -309	  -309	  -310	  -310	  -312	  -310	  -311	  -311	  -311	  -311	  -311	  -312	  -311	  -310	  -310	  -309	  -311	  -310	  -310	  -308	  -306	  -301	  -300	  -301	  -301	  -303	  -303	  -303	  -302	  -303	  -302	  -304	  -305	  -303	  -304	  -305	  -302	  -306	  -315	  -303	  -302	  -302	  -301	  -299	  -298	  -297	  -297	  -296	  -295	  -297	  -295	  -296	  -296	  -295	  -297	  -297	  -297	  -295	  -292	  -293	  -291	  -290	  -289	  -291	  -290	  -291	  -292	  -292	  -291	  -289	  -291	  -289	  -289	  -289	  -292	  -291	  -290	  -288	  -285	  -285	  -286	  -282	  -283	  -285	  -284	  -283	  -284	  -284	  -283	  -284	  -284	  -284	  -284	  -283	  -283	  -280	  -278	  -276	  -277	  -275	  -277	  -276	  -276	  -277	  -278	  -274	  -272	  -271	  -272	  -272	  -271	  -269	  -270	  -271	  -273	  -273	  -273	  -271	  -269	  -266	  -262	  -262	  -262	  -265	  -263	  -264	  -265	  -264	  -265	  -263	  -264	  -262	  -261	  -258	  -259	  -259	  -258	  -258	  -259	  -259	  -258	  -256	  -255	  -254	  -254	  -252	  -253	  -253	  -252	  -251	  -252	  -252	  -254	  -252	  -250	  -250	  -250	  -249	  -248	  -246	  -246	  -247	  -245	  -245	  -246	  -244	  -243	  -243	  -242	  -242	  -244	  -241	  -242	  -241	  -238	  -237	  -237	  -237	  -236	  -235	  -235	  -236	  -236	  -235	  -233	  -232	  -231	  -229	  -229	  -229	  -228	  -233	  -232	  -229	  -230	  -227	  -225	  -223	  -218	  -221	  -222	  -223	  -222	  -221	  -219	  -219	  -216	  -217	  -217	  -220	  -219	  -217	  -219	  -216	  -214	  -212	  -209	  -211	  -212	  -211	  -211	  -209	  -207	  -207	  -207	  -204	  -205	  -204	  -204	  -199	  -204	  -203	  -199	  -201	  -201	  -202	  -205	  -201	  -199	  -198	  -197	  -196	  -197	  -195	  -193	  -192	  -192	  -191	  -191	  -190	  -191	  -192	  -191	  -191	  -191	  -187	  -188	  -186	  -185	  -185	  -186	  -185	  -182	  -180	  -179	  -179	  -176	  -176	  -178	  -175	  -176	  -174	  -174	  -173	  -174	  -173	  -172	  -171	  -171	  -168	  -167	  -166	  -166	  -166	  -166	  -165	  -165	  -163	  -159	  -160	  -163	  -161	  -160	  -160	  -159	  -156	  -157	  -155	  -156	  -156	  -153	  -152	  -154	  -152	  -149	  -150	  -148	  -146	  -145	  -146	  -144	  -146	  -145	  -142	  -143	  -142	  -141	  -141	  -142	  -141	  -140	  -139	  -137	  -135	  -135	  -131	  -135	  -133	  -137	  -136	  -134	  -135	  -133	  -129	  -128	  -125	  -122	  -121	  -121	  -122	  -122	  -120	  -121	  -122	  -121	  -120	  -120	  -117	  -116	  -115	  -116	  -114	  -113	  -110	  -109	  -108	  -106	  -106	  -107	  -107	  -108	  -108	  -108	  -103	  -102	  -100	  -100	  -100	  -105	  -103	  -102	  -102	  -102	  -99	  -97	  -92	  -89	  -87	  -88	  -88	  -89	  -89	  -88	  -88	  -87	  -86	  -85	  -85	  -83	  -84	  -84	  -82	  -81	  -79	  -78	  -76	  -73	  -74	  -76	  -72	  -72	  -74	  -72	  -70	  -71	  -70	  -67	  -65	  -65	  -64	  -65	  -64	  -67	  -65	  -63	  -62	  -61	  -61	  -56	  -57	  -59	  -57	  -57	  -56	  -54	  -52	  -49	  -50	  -50	  -47	  -46	  -49	  -44	  -44	  -46	  -45	  -45	  -42	  -39	  -37	  -39	  -38	  -38	  -37	  -38	  -39	  -38	  -36	  -31	  -29	  -27	  -26	  -25	  -24	  -19	  -25	  -28	  -27	  -26	  -26	  -25	  -23	  -19	  -17	  -20	  -17	  -16	  -18	  -19	  -17	  -16	  -14	  -10	  -11	  -11	  -10	  -9	  -5	  -5	  -5	  -7	  -7	  -8	  -5	  -1	  -1	  2	  5	  6	  7	  7	  7	  5	  9	  8	  10	  11	  11	  12	  15	  10	  9	  11	  13	  14	  17	  19	  20	  22	  23	  23	  22	  22	  23	  25	  25	  26	  27	  28	  30	  31	  31	  31	  31	  31	  34	  34	  35	  37	  38	  40	  40	  43	  42	  43	  45	  45	  47	  45	  44	  46	  47	  48	  49	  51	  52	  54	  53	  52	  55	  56	  56	  59	  61	  60	  61	  60	  61	  63	  65	  65	  64	  65	  67	  68	  70	  71	  73	  72	  70	  70	  71	  69	  73	  72	  74	  78	  79	  79	  82	  83	  85	  86	  84	  84	  81	  83	  85	  86	  88	  88	  91	  93	  94	  95	  94	  92	  93	  95	  96	  98	  99	  102	  104	  105	  103	  102	  104	  103	  107	  107	  108	  108	  107	  107	  111	  108	  109	  108	  108	  111	  114	  118	  118	  121	  119	  117	  117	  117	  118	  121	  122	  123	  123	  125	  127	  129	  130	  125	  127	  127	  125	  127	  128	  129	  132	  132	  132	  134	  131	  133	  134	  136   140	  141	  142	  142	  142	  143	  141	  141	  141	  142	  143	  145	  147	  148	  155	  155	  155	  153	  152	  154	  155	  155	  159	  161	  159	  159	  158	  158	  160	  163	  162	  163	  165	  165	  166	  164	  162	  165	  167	  167	  168	  170	  171	  171	  172	  174	  174	  173	  174	  174	  177	  177	  179	  177	  177	  175	  175	  177	  178	  181	  183	  186	  187	  186	  187	  187	  188	  189	  191	  189	  190	  191	  193	  195	  196	  200	  196	  195	  197	  199	  198	  197	  199	  199	  199	  197	  197	  199	  202	  204	  207	  208	  206	  206	  206	  207	  206	  209	  210	  210	  209	  209	  208	  209	  211	  212	  215	  215	  215	  215	  216	  217	  217	  219	  219	  219	  223	  219	  221	  222	  223	  225	  226	  224	  226	  227	  228	  229	  227	  228	  231	  232	  233	  233	  234	  232	  231	  232	  232	  235	  237	  237	  239	  237	  235	  239	  239	  239	  243	  242	  241	  243	  243	  242	  243	  245	  246	  247	  245	  246	  246	  245	  247	  248	  250	  251	  252	  251	  248	  248	  246	  249	  249	  249	  254	  255	  255	  252	  253	  254	  255	  255	  257	  258	  260	  262	  260	  261	  260	  262	  263	  265	  265	  266	  267	  265	  264	  265	  265	  268	  269	  269	  268	  268	  265	  263	  267	  267	  270	  269	  271	  272	  274	  271	  272	  275	  275	  275	  277	  277	  279	  281	  279	  278	  278	  278	  278	  279	  280	  281	  281	  282	  283	  284	  283	  281	  282	  281	  283	  283	  281	  283	  284	  283	  286	  286	  287	  288	  287	  286	  286	  286	  285	  288	  289	  290	  291	  295	  294	  293	  290	  289	  289	  290	  291	  291	  292	  293	  296	  299	  300	  299	  298	  296	  295	  293	  295	  296	  297	  297	  299	  298	  298	  300	  300	  300	  300	  297	  296	  299	  298	  296	  296	  300	  300	  305	  306	  307	  305	  302	  302	  305	  305	  304	  304	  303	  303	  306	  307	  309	  311	  311	  310	  307	  308	  307	  307	  309	  307	  306	  306	  308	  308	  307	  303	  307	  307	  310	  311	  311	  309	  310	  311	  308	  309	  309	  309	  311	  313	  311	  311	  310	  309	  309	  313	  314	  313	  315	  314	  315	  316	  315	  315	  315	  315	  315	  315	  313	  314	  314	  314	  314	  314	  312	  313	  313	  314	  313	  313	  314	  317	  319	  317	  319	  319	  319	  318	  316	  318	  319	  319	  368	  425	  432	  472	  477	  451	  462	  469	  475	  511	  488	  501	  511	  511	  484	  477	  493	  471	  466	  460	  469	  483	  511	  484	  500	  511	  511	  481	  479	  475	  475	  509	  489	  493	  511	  511	  497	  473	  493	  483	  461	  473	  495	  486	  458	  465	  470	  474	  509	  482	  490	  511	  511	  488	  474	  487	  463	  465	  462	  469	  477	  511	  477	  495	  511	  511	  475	  479	  479	  498	  511	  511	  481	  471	  490	  467	  463	  457	  465	  473	  508	  476	  482	  477	  473	  473	  511	  478	  490	  511	  511	  478	  470	  486	  466	  460	  471	  479	  460	  483	  481	  452	  458	  460	  462	  501	  474	  485	  511	  498	  511	  493	  487	  510	  506	  492	  465	  485	  477	  449	  453	  455	  457	  466	  487	  453	  463	  474	  444	  453	  449	  455	  474	  489	  471	  491	  495	  478	  452	  473	  470	  440	  447	  451	  453	  490	  467	  473	  501	  499	  471	  472	  497	  490	  472	  449	  462	  457	  434	  437	  443	  445	  481	  454	  463	  456	  483	  459	  465	  491	  487	  461	  443	  463	  451	  434	  434	  439	  458	  450	  422	  429	  434	  435	  473	  446	  456	  484	  483	  453	  437	  453	  389	  337	  306	  292	  286	  282	  282	  281	  279	  276	  275	  275	  275	  277	  276	  275	  275	  275	  275	  277	  274	  272	  269	  271	  271	  273	  271	  270	  269	  267	  267	  268	  271	  271	  272	  272	  269	  269	  267	  265	  263	  263	  263	  263	  262	  258	  260	  262	  263	  261	  262	  261	  260	  259	  257	  257	  257	  257	  255	  255	  256	  258	  260	  255	  255	  255	  252	  253	  253	  251	  252	  253	  254	  255	  254	  251	  251	  249	  247	  247	  244	  244	  243	  244	  244	  244	  243	  244	  242	  241	  239	  240	  241	  240	  240	  240	  241	  241	  241	  239	  237	  235	  233	  235	  235	  235	  235	  234	  233	  232	  231	  229	  228	  224	  225	  226	  227	  228	  227	  226	  223	  225	  223	  223	  223	  225	  222];

plot(locked_samples)