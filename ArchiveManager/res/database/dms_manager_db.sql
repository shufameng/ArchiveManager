/*
Navicat MySQL Data Transfer

Source Server         : test
Source Server Version : 50712
Source Host           : localhost:3306
Source Database       : dms_manager_db_zb

Target Server Type    : MYSQL
Target Server Version : 50712
File Encoding         : 65001

Date: 2017-04-01 16:12:35
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `archive_book`
-- ----------------------------
DROP TABLE IF EXISTS `archive_book`;
CREATE TABLE `archive_book` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `type` int(11) NOT NULL DEFAULT '106' COMMENT '案卷类型',
  `qzh` varchar(32) NOT NULL COMMENT '全宗号',
  `mlh` varchar(32) NOT NULL COMMENT '目录号',
  `ajh` varchar(32) NOT NULL COMMENT '案卷号',
  `jh` varchar(32) NOT NULL COMMENT '件号',
  `tm` varchar(256) DEFAULT NULL COMMENT '题名',
  `zrz` varchar(64) DEFAULT NULL COMMENT '责任者',
  `bgqx` varchar(64) DEFAULT NULL COMMENT '保管期限',
  `jgwt` varchar(32) DEFAULT NULL COMMENT '机构问题',
  `jglb` varchar(64) DEFAULT NULL COMMENT '机构类别',
  `mj` varchar(64) DEFAULT NULL COMMENT '密级',
  `wh` varchar(128) DEFAULT NULL COMMENT '文号',
  `mldm` varchar(32) DEFAULT NULL COMMENT '档案门类代码',
  `nd` varchar(11) DEFAULT NULL COMMENT '年度',
  `gdh` varchar(128) DEFAULT NULL COMMENT '归档号',
  `ztlx` varchar(32) DEFAULT NULL COMMENT '载体类型',
  `flh` varchar(32) DEFAULT NULL COMMENT '分类号',
  `ztc` varchar(64) DEFAULT NULL COMMENT '主题词',
  `sj` varchar(64) DEFAULT NULL COMMENT '时间',
  `dh` varchar(64) DEFAULT NULL COMMENT '档号',
  `wsh` varchar(64) DEFAULT NULL COMMENT '微缩号',
  `yh` varchar(32) DEFAULT NULL COMMENT '页号',
  `zs` varchar(11) DEFAULT NULL COMMENT '张数',
  `kfh` varchar(32) DEFAULT NULL COMMENT '库房号',
  `pjh` varchar(32) DEFAULT NULL COMMENT '排架号',
  `bz` varchar(128) DEFAULT NULL COMMENT '备注',
  `create_time` datetime DEFAULT NULL COMMENT '录入数据库时间',
  `update_time` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '最后更新时间',
  `j000` varchar(256) DEFAULT NULL,
  `j001` varchar(256) DEFAULT NULL,
  `j002` varchar(256) DEFAULT NULL,
  `j003` varchar(256) DEFAULT NULL,
  `j004` varchar(256) DEFAULT NULL,
  `j005` varchar(256) DEFAULT NULL,
  `j006` varchar(256) DEFAULT NULL,
  `j007` varchar(256) DEFAULT NULL,
  `j008` varchar(256) DEFAULT NULL,
  `j009` varchar(256) DEFAULT NULL,
  `j010` varchar(256) DEFAULT NULL,
  `j011` varchar(256) DEFAULT NULL,
  `j012` varchar(256) DEFAULT NULL,
  `j013` varchar(256) DEFAULT NULL,
  `j014` varchar(256) DEFAULT NULL,
  `j015` varchar(256) DEFAULT NULL,
  `j016` varchar(256) DEFAULT NULL,
  `j017` varchar(256) DEFAULT NULL,
  `j018` varchar(256) DEFAULT NULL,
  `j019` varchar(256) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `query_index1` (`qzh`,`mlh`,`ajh`,`jh`) USING BTREE,
  KEY `query_index2` (`qzh`,`mlh`,`ajh`,`jh`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of archive_book
-- ----------------------------

-- ----------------------------
-- Table structure for `archive_box`
-- ----------------------------
DROP TABLE IF EXISTS `archive_box`;
CREATE TABLE `archive_box` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `type` int(11) NOT NULL DEFAULT '106' COMMENT '案卷类型',
  `qzh` varchar(32) NOT NULL COMMENT '全宗号',
  `mlh` varchar(32) NOT NULL COMMENT '目录号',
  `ajh` varchar(32) NOT NULL COMMENT '案卷号',
  `tm` varchar(256) DEFAULT NULL COMMENT '题名',
  `jgwt` varchar(32) DEFAULT NULL COMMENT '机构问题',
  `jglb` varchar(32) DEFAULT NULL COMMENT '机构类别',
  `mldm` varchar(32) DEFAULT NULL COMMENT '档案门类代码',
  `nd` varchar(11) DEFAULT NULL COMMENT '年度',
  `ys` varchar(11) DEFAULT NULL COMMENT '页数',
  `gdh` varchar(128) DEFAULT NULL COMMENT '归档号',
  `flh` varchar(32) DEFAULT NULL COMMENT '分类号',
  `qssj` varchar(64) DEFAULT NULL COMMENT '起始时间',
  `zzsj` varchar(64) DEFAULT NULL COMMENT '终止时间',
  `bgqx` varchar(32) DEFAULT NULL COMMENT '保管期限',
  `dagdm` varchar(32) DEFAULT NULL COMMENT '档案馆代码',
  `zrz` varchar(64) DEFAULT NULL COMMENT '责任者',
  `kfh` varchar(32) DEFAULT NULL COMMENT '库房号',
  `pjh` varchar(32) DEFAULT NULL COMMENT '排架号',
  `bz` varchar(128) DEFAULT NULL COMMENT '备注',
  `create_time` datetime DEFAULT NULL COMMENT '录入数据库时间',
  `update_time` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '最后修改时间',
  `A000` varchar(256) DEFAULT NULL,
  `A001` varchar(256) DEFAULT NULL,
  `A002` varchar(256) DEFAULT NULL,
  `A003` varchar(256) DEFAULT NULL,
  `A004` varchar(256) DEFAULT NULL,
  `A005` varchar(256) DEFAULT NULL,
  `A006` varchar(256) DEFAULT NULL,
  `A007` varchar(256) DEFAULT NULL,
  `A008` varchar(256) DEFAULT NULL,
  `A009` varchar(256) DEFAULT NULL,
  `A010` varchar(256) DEFAULT NULL,
  `A011` varchar(256) DEFAULT NULL,
  `A012` varchar(256) DEFAULT NULL,
  `A013` varchar(256) DEFAULT NULL,
  `A014` varchar(256) DEFAULT NULL,
  `A015` varchar(256) DEFAULT NULL,
  `A016` varchar(256) DEFAULT NULL,
  `A017` varchar(256) DEFAULT NULL,
  `A018` varchar(256) DEFAULT NULL,
  `A019` varchar(256) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `query_index1` (`qzh`,`mlh`,`ajh`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of archive_box
-- ----------------------------

-- ----------------------------
-- Table structure for `archive_fonds`
-- ----------------------------
DROP TABLE IF EXISTS `archive_fonds`;
CREATE TABLE `archive_fonds` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `qzh` varchar(32) NOT NULL COMMENT '全宗号',
  `qztm` varchar(256) DEFAULT NULL COMMENT '全宗题名',
  `kfh` varchar(128) DEFAULT NULL COMMENT '库房号',
  `pjh` varchar(128) DEFAULT NULL COMMENT '排架号',
  `qssj` varchar(64) DEFAULT NULL COMMENT '起始时间',
  `zzsj` varchar(64) DEFAULT NULL COMMENT '终止时间',
  `bz` varchar(256) DEFAULT NULL COMMENT '备注',
  `create_time` datetime DEFAULT NULL COMMENT '录入数据库时间',
  `update_time` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '最后修改时间',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of archive_fonds
-- ----------------------------

-- ----------------------------
-- Table structure for `archive_library`
-- ----------------------------
DROP TABLE IF EXISTS `archive_library`;
CREATE TABLE `archive_library` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `name` varchar(128) NOT NULL COMMENT '档案馆名称',
  `db_name` varchar(64) NOT NULL COMMENT '数据库_表名',
  `remarks` varchar(256) DEFAULT NULL COMMENT '备注',
  `create_time` datetime DEFAULT NULL COMMENT '录入数据库时间',
  `update_time` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '最后更新时间',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of archive_library
-- ----------------------------
INSERT INTO `archive_library` VALUES ('1', '默认档案馆', 'dms_manager_db', null, '2017-01-19 17:59:35', '2017-02-14 22:24:35');

-- ----------------------------
-- Table structure for `archive_media`
-- ----------------------------
DROP TABLE IF EXISTS `archive_media`;
CREATE TABLE `archive_media` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `dalx` tinyint(1) NOT NULL DEFAULT '1' COMMENT '1为卷内文件，2为归档文件',
  `qzh` varchar(64) DEFAULT NULL COMMENT '全宗号',
  `mlh` varchar(64) DEFAULT NULL COMMENT '目录号,归档由档案门类代码.年度组成',
  `ajh` varchar(64) DEFAULT NULL COMMENT '案卷号，归档由',
  `jh` varchar(64) DEFAULT NULL COMMENT '件号',
  `wjm` varchar(128) DEFAULT NULL COMMENT '文件名',
  `ocr_text` varchar(21000) DEFAULT NULL,
  PRIMARY KEY (`ID`),
  KEY `query_index1` (`qzh`,`mlh`,`ajh`,`jh`) USING BTREE,
  KEY `query_index2` (`qzh`,`mlh`,`ajh`,`jh`,`wjm`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of archive_media
-- ----------------------------

-- ----------------------------
-- Table structure for `log`
-- ----------------------------
DROP TABLE IF EXISTS `log`;
CREATE TABLE `log` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `user_id` bigint(20) NOT NULL,
  `library_id` bigint(20) NOT NULL,
  `operation` varchar(256) DEFAULT NULL,
  `update_time` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of log
-- ----------------------------

-- ----------------------------
-- Table structure for `org_type`
-- ----------------------------
DROP TABLE IF EXISTS `org_type`;
CREATE TABLE `org_type` (
  `name` varchar(128) NOT NULL,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of org_type
-- ----------------------------
INSERT INTO `org_type` VALUES ('会议');
INSERT INTO `org_type` VALUES ('其它');
INSERT INTO `org_type` VALUES ('发文');
INSERT INTO `org_type` VALUES ('来文');

-- ----------------------------
-- Table structure for `search_record`
-- ----------------------------
DROP TABLE IF EXISTS `search_record`;
CREATE TABLE `search_record` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `qzh` varchar(64) DEFAULT NULL COMMENT '全宗号',
  `mlh` varchar(64) DEFAULT NULL COMMENT '目录号',
  `ajh` varchar(64) DEFAULT NULL COMMENT '案卷号',
  `jh` varchar(64) DEFAULT NULL COMMENT '件号',
  `customer` varchar(64) DEFAULT NULL COMMENT '查档人',
  `id_card_num` varchar(64) DEFAULT NULL,
  `op_reason` varchar(256) DEFAULT NULL COMMENT '查档原因',
  `op_person` varchar(64) DEFAULT NULL COMMENT '操作人员',
  `op_time` datetime DEFAULT NULL COMMENT '查档时间',
  `remarks` varchar(256) DEFAULT NULL COMMENT '备注',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of search_record
-- ----------------------------

-- ----------------------------
-- Table structure for `secret_level`
-- ----------------------------
DROP TABLE IF EXISTS `secret_level`;
CREATE TABLE `secret_level` (
  `name` varchar(128) NOT NULL,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of secret_level
-- ----------------------------
INSERT INTO `secret_level` VALUES ('公开');
INSERT INTO `secret_level` VALUES ('机密');
INSERT INTO `secret_level` VALUES ('秘密');
INSERT INTO `secret_level` VALUES ('绝密');

-- ----------------------------
-- Table structure for `time_limit`
-- ----------------------------
DROP TABLE IF EXISTS `time_limit`;
CREATE TABLE `time_limit` (
  `name` varchar(128) NOT NULL,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of time_limit
-- ----------------------------
INSERT INTO `time_limit` VALUES ('三十年');
INSERT INTO `time_limit` VALUES ('十年');
INSERT INTO `time_limit` VALUES ('永久');
INSERT INTO `time_limit` VALUES ('长期');

-- ----------------------------
-- Table structure for `user`
-- ----------------------------
DROP TABLE IF EXISTS `user`;
CREATE TABLE `user` (
  `ID` bigint(20) NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL COMMENT '用户名',
  `role` bigint(20) NOT NULL COMMENT '用户角色',
  `password` varchar(32) DEFAULT NULL COMMENT '密码',
  `remarks` varchar(256) DEFAULT NULL COMMENT '备注',
  `create_time` datetime DEFAULT NULL,
  `update_time` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '更新时间',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of user
-- ----------------------------
INSERT INTO `user` VALUES ('1', 'admin', '3', 'admin', '默认的管理员用户', null, '2017-01-26 16:37:55');

-- ----------------------------
-- Table structure for `user_def_fileds`
-- ----------------------------
DROP TABLE IF EXISTS `user_def_fileds`;
CREATE TABLE `user_def_fileds` (
  `id` bigint(20) NOT NULL AUTO_INCREMENT,
  `type` int(11) NOT NULL COMMENT '档案类型',
  `table_name` varchar(256) NOT NULL COMMENT '表明',
  `field_name` varchar(256) NOT NULL COMMENT '字段名称',
  `custom_name` varchar(256) NOT NULL COMMENT '用户自定义的名称',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of user_def_fileds
-- ----------------------------
