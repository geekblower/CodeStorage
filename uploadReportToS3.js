uploadReportToS3(contentType, base64, name, bucketName, metaData = null) {
        const s3 = new Aws.S3();
        const base64Data = new Buffer.from(base64.replace(/^data:\/\w+;base64,/, ""), 'base64');
        let params = {
            Bucket: bucketName,
            Key: name,
            Body: base64Data,
            ACL: 'public-read',
            ContentEncoding:"base64",
            ContentType: contentType
        };
        if (metaData) {
            params['Metadata'] = metaData
        }

        try {
            const { Location, Key } = await s3.upload(params).promise();
            return { Location, Key};
        } catch (error) {
            return error;
        }
    }
