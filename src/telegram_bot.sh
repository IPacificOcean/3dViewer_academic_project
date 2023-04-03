#!/bin/bash

TELEGRAM_BOT_TOKEN="6272963407:AAFt85VTdzq-te4nQvDOkQ_9gmVXLG3oT00"
TELEGRAM_USER_ID_TYSANENO="314168388"
TELEGRAM_USER_ID_VIOLATOR="579950685"
TELEGRAM_USER_ID_QYBURNBO="198632649"
TIME="10"

URL="https://api.telegram.org/bot$TELEGRAM_BOT_TOKEN/sendMessage"
TEXT="Job name: $CI_JOB_NAME%0A%0AStatus: $1%0A%0AProject:+$CI_PROJECT_NAME%0AURL:+$CI_PROJECT_URL/pipelines/$CI_PIPELINE_ID/%0ABranch:+$CI_COMMIT_REF_SLUG"

curl -s --max-time $TIME -d "chat_id=$TELEGRAM_USER_ID_TYSANENO&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null
curl -s --max-time $TIME -d "chat_id=$TELEGRAM_USER_ID_VIOLATOR&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null
curl -s --max-time $TIME -d "chat_id=$TELEGRAM_USER_ID_QYBURNBO&disable_web_page_preview=1&text=$TEXT" $URL > /dev/null