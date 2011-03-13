/**
 * Implements behaviors.
 *
 * @param context
 */
Drupal.behaviors.seckit = function(context) {
  seckit_listener_sts($('#edit-seckit-ssl-sts', context));
  seckit_listener_csp($('#edit-seckit-xss-csp-checkbox', context));
  $('#edit-seckit-ssl-sts', context).click(function() {
    seckit_listener_sts(this)
  });
  $('#edit-seckit-xss-csp-checkbox', context).click(function() {
    seckit_listener_csp(this)
  });
  $('#edit-seckit-csrf-origin', context).click(function() {
    seckit_listener_origin(this)
  });
}

/**
 * Gets checkbox status and executes necessary functions
 * to Strict-Transport-Security fieldset.
 *
 * @param element
 */
function seckit_listener_sts(element) {
  if ($(element).is(':checked')) {
    seckit_listener_enable_sts(element);
  }
  else {
    seckit_listener_disable_sts(element);
  }
}

/**
 * Gets checkbox status and executes necessary functions
 * to Content Security Policy fieldset.
 *
 * @param element
 */
function seckit_listener_csp(element) {
  if ($(element).is(':checked')) {
    seckit_listener_enable_csp(element);
  }
  else {
    seckit_listener_disable_csp(element);
  }
}

/**
 * Gets checkbox status and executes necessary functions
 * to Origin fieldset.
 *
 * @param element
 */
function seckit_listener_origin(element) {
  if ($(element).is(':checked')) {
    seckit_listener_enable_origin(element);
  }
  else {
    seckit_listener_disable_origin(element);
  }
}

/**
 * Enables Content Security Policy form elements.
 *
 * @param element
 */
function seckit_listener_enable_csp(element) {
  $('#edit-seckit-xss-csp-allow').removeAttr('disabled');
  $('#edit-seckit-xss-csp-options').removeAttr('disabled');
  $('#edit-seckit-xss-csp-img-src').removeAttr('disabled');
  $('#edit-seckit-xss-csp-media-src').removeAttr('disabled');
  $('#edit-seckit-xss-csp-script-src').removeAttr('disabled');
  $('#edit-seckit-xss-csp-object-src').removeAttr('disabled');
  $('#edit-seckit-xss-csp-frame-src').removeAttr('disabled');
  $('#edit-seckit-xss-csp-font-src').removeAttr('disabled');
  $('#edit-seckit-xss-csp-xhr-src').removeAttr('disabled');
  $('#edit-seckit-xss-csp-style-src').removeAttr('disabled');
  $('#edit-seckit-xss-csp-frame-ancestors').removeAttr('disabled');
  $('label[for="edit-seckit-xss-csp-allow"]').append('<span title="' + Drupal.t('This field is required.') + '" class="form-required">*</span>');
}

/**
 * Disables Content Security Policy form elements.
 *
 * @param element
 */
function seckit_listener_disable_csp(element) {
  $('#edit-seckit-xss-csp-allow').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-options').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-img-src').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-media-src').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-script-src').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-object-src').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-frame-src').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-font-src').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-xhr-src').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-style-src').attr('disabled', 'disabled');
  $('#edit-seckit-xss-csp-frame-ancestors').attr('disabled', 'disabled');
  $('span[title="' + Drupal.t('This field is required.') + '"]').remove();
}

/**
 * Enables Origin form elements.
 *
 * @param element
 */
function seckit_listener_enable_origin(element) {
  $('#edit-seckit-csrf-origin-whitelist').removeAttr('disabled');
}

/**
 * Disables Origin form elements.
 *
 * @param element
 */
function seckit_listener_disable_origin(element) {
  $('#edit-seckit-csrf-origin-whitelist').attr('disabled', 'disabled');
}

/**
 * Enables Strict-Transport-Security form elements.
 *
 * @param element
 */
function seckit_listener_enable_sts(element) {
  $('#edit-seckit-ssl-sts-max-age').removeAttr('disabled');
  $('#edit-seckit-ssl-sts-subdomains').removeAttr('disabled');
}

/**
 * Disables Strict-Transport-Security form elements.
 *
 * @param element
 */
function seckit_listener_disable_sts(element) {
  $('#edit-seckit-ssl-sts-max-age').attr('disabled', 'disabled');
  $('#edit-seckit-ssl-sts-subdomains').attr('disabled', 'disabled');
}