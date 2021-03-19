// megafunction wizard: %FIR II v18.1%
// GENERATION: XML
// rx_ciccomp.v

// Generated using ACDS version 18.1 625

`timescale 1 ps / 1 ps
module rx_ciccomp (
		input  wire        clk,              //                     clk.clk
		input  wire        reset_n,          //                     rst.reset_n
		input  wire [31:0] ast_sink_data,    //   avalon_streaming_sink.data
		input  wire        ast_sink_valid,   //                        .valid
		input  wire [1:0]  ast_sink_error,   //                        .error
		output wire [61:0] ast_source_data,  // avalon_streaming_source.data
		output wire        ast_source_valid, //                        .valid
		output wire [1:0]  ast_source_error  //                        .error
	);

	rx_ciccomp_0002 rx_ciccomp_inst (
		.clk              (clk),              //                     clk.clk
		.reset_n          (reset_n),          //                     rst.reset_n
		.ast_sink_data    (ast_sink_data),    //   avalon_streaming_sink.data
		.ast_sink_valid   (ast_sink_valid),   //                        .valid
		.ast_sink_error   (ast_sink_error),   //                        .error
		.ast_source_data  (ast_source_data),  // avalon_streaming_source.data
		.ast_source_valid (ast_source_valid), //                        .valid
		.ast_source_error (ast_source_error)  //                        .error
	);

endmodule
// Retrieval info: <?xml version="1.0"?>
//<!--
//	Generated by Altera MegaWizard Launcher Utility version 1.0
//	************************************************************
//	THIS IS A WIZARD-GENERATED FILE. DO NOT EDIT THIS FILE!
//	************************************************************
//	Copyright (C) 1991-2021 Altera Corporation
//	Any megafunction design, and related net list (encrypted or decrypted),
//	support information, device programming or simulation file, and any other
//	associated documentation or information provided by Altera or a partner
//	under Altera's Megafunction Partnership Program may be used only to
//	program PLD devices (but not masked PLD devices) from Altera.  Any other
//	use of such megafunction design, net list, support information, device
//	programming or simulation file, or any other related documentation or
//	information is prohibited for any other purpose, including, but not
//	limited to modification, reverse engineering, de-compiling, or use with
//	any other silicon devices, unless such use is explicitly licensed under
//	a separate agreement with Altera or a megafunction partner.  Title to
//	the intellectual property, including patents, copyrights, trademarks,
//	trade secrets, or maskworks, embodied in any such megafunction design,
//	net list, support information, device programming or simulation file, or
//	any other related documentation or information provided by Altera or a
//	megafunction partner, remains with Altera, the megafunction partner, or
//	their respective licensors.  No other licenses, including any licenses
//	needed under any third party's intellectual property, are provided herein.
//-->
// Retrieval info: <instance entity-name="altera_fir_compiler_ii" version="18.1" >
// Retrieval info: 	<generic name="filterType" value="decim" />
// Retrieval info: 	<generic name="interpFactor" value="1" />
// Retrieval info: 	<generic name="decimFactor" value="2" />
// Retrieval info: 	<generic name="symmetryMode" value="nsym" />
// Retrieval info: 	<generic name="L_bandsFilter" value="1" />
// Retrieval info: 	<generic name="inputChannelNum" value="1" />
// Retrieval info: 	<generic name="clockRate" value="122.880" />
// Retrieval info: 	<generic name="clockSlack" value="24" />
// Retrieval info: 	<generic name="inputRate" value="0.768" />
// Retrieval info: 	<generic name="coeffReload" value="false" />
// Retrieval info: 	<generic name="baseAddress" value="0" />
// Retrieval info: 	<generic name="readWriteMode" value="read_write" />
// Retrieval info: 	<generic name="backPressure" value="false" />
// Retrieval info: 	<generic name="deviceFamily" value="Cyclone IV E" />
// Retrieval info: 	<generic name="speedGrade" value="slow" />
// Retrieval info: 	<generic name="delayRAMBlockThreshold" value="20" />
// Retrieval info: 	<generic name="dualMemDistRAMThreshold" value="1280" />
// Retrieval info: 	<generic name="mRAMThreshold" value="1000000" />
// Retrieval info: 	<generic name="hardMultiplierThreshold" value="10" />
// Retrieval info: 	<generic name="reconfigurable" value="false" />
// Retrieval info: 	<generic name="num_modes" value="2" />
// Retrieval info: 	<generic name="reconfigurable_list" value="0" />
// Retrieval info: 	<generic name="MODE_STRING" value="None Set" />
// Retrieval info: 	<generic name="channelModes" value="0,1,2,3" />
// Retrieval info: 	<generic name="inputType" value="int" />
// Retrieval info: 	<generic name="inputBitWidth" value="32" />
// Retrieval info: 	<generic name="inputFracBitWidth" value="0" />
// Retrieval info: 	<generic name="coeffSetRealValue" value="-461.0,-2533.0,469.0,2760.0,-507.0,-3154.0,564.0,3721.0,-648.0,-4486.0,748.0,5453.0,-873.0,-6651.0,1010.0,8087.0,-1167.0,-9790.0,1330.0,11773.0,-1507.0,-14068.0,1683.0,16693.0,-1867.0,-19694.0,2036.0,23094.0,-2201.0,-26952.0,2339.0,31308.0,-2459.0,-36251.0,2531.0,41851.0,-2558.0,-48243.0,2498.0,55543.0,-2365.0,-64001.0,2083.0,73858.0,-1640.0,-85561.0,907.0,99644.0,188.0,-117072.0,-1932.0,139220.0,4654.0,-168684.0,-9385.0,209821.0,17904.0,-272265.0,-36047.0,378084.0,82929.0,-596135.0,-269551.0,1210913.0,2097151.0,1210913.0,-269551.0,-596135.0,82929.0,378084.0,-36047.0,-272265.0,17904.0,209821.0,-9385.0,-168684.0,4654.0,139220.0,-1932.0,-117072.0,188.0,99644.0,907.0,-85561.0,-1640.0,73858.0,2083.0,-64001.0,-2365.0,55543.0,2498.0,-48243.0,-2558.0,41851.0,2531.0,-36251.0,-2459.0,31308.0,2339.0,-26952.0,-2201.0,23094.0,2036.0,-19694.0,-1867.0,16693.0,1683.0,-14068.0,-1507.0,11773.0,1330.0,-9790.0,-1167.0,8087.0,1010.0,-6651.0,-873.0,5453.0,748.0,-4486.0,-648.0,3721.0,564.0,-3154.0,-507.0,2760.0,469.0,-2533.0,-461.0" />
// Retrieval info: 	<generic name="coeffSetRealValueImag" value="0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -0.0530093, -0.04498, 0.0, 0.0749693, 0.159034, 0.224907, 0.249809, 0.224907, 0.159034, 0.0749693, 0.0, -0.04498, -0.0530093, -0.0321283, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0" />
// Retrieval info: 	<generic name="coeffScaling" value="auto" />
// Retrieval info: 	<generic name="coeffType" value="int" />
// Retrieval info: 	<generic name="coeffBitWidth" value="22" />
// Retrieval info: 	<generic name="coeffFracBitWidth" value="31" />
// Retrieval info: 	<generic name="coeffComplex" value="false" />
// Retrieval info: 	<generic name="karatsuba" value="false" />
// Retrieval info: 	<generic name="outType" value="int" />
// Retrieval info: 	<generic name="outMSBRound" value="trunc" />
// Retrieval info: 	<generic name="outMsbBitRem" value="0" />
// Retrieval info: 	<generic name="outLSBRound" value="round" />
// Retrieval info: 	<generic name="outLsbBitRem" value="0" />
// Retrieval info: 	<generic name="bankCount" value="1" />
// Retrieval info: 	<generic name="bankDisplay" value="0" />
// Retrieval info: </instance>
// IPFS_FILES : rx_ciccomp.vo
// RELATED_FILES: rx_ciccomp.v, dspba_library_package.vhd, dspba_library.vhd, auk_dspip_math_pkg_hpfir.vhd, auk_dspip_lib_pkg_hpfir.vhd, auk_dspip_avalon_streaming_controller_hpfir.vhd, auk_dspip_avalon_streaming_sink_hpfir.vhd, auk_dspip_avalon_streaming_source_hpfir.vhd, auk_dspip_roundsat_hpfir.vhd, altera_avalon_sc_fifo.v, rx_ciccomp_0002_rtl_core.vhd, rx_ciccomp_0002_ast.vhd, rx_ciccomp_0002.vhd
